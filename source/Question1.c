#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/stat.h>
#include <stdbool.h>
int m, n;
void* threadRun(void* t);
bool IsSafe();
void show();
int Request(int index, int rq[]);
void Release(int index, int rl[]);
int safe[100] = {0};
int ava[100] = {0};
int max[100][100] = {0};
int allo[100][100] = {0};
int need[100][100] = {0};
bool finish[100];

int main(int argc, char* argv[]){
	if (argc == 0){
		printf("Input file name missing...exiting with error code -1\n");
		return -1;
	}

	m = argc - 1;

	for (int i = 0; i < m; i++){
		ava[i] = atol(argv[i+1]);
	}

	FILE *in = fopen("sample4_in.txt", "r");
	struct stat st;
	fstat(fileno(in), &st);
	char* fcontent = (char*)malloc(((int)st.st_size+1)*sizeof(char));
	fcontent[0] = '\0';
	while (!feof(in)){
		char line[50];
		if (fgets(line, 50, in) != NULL){
			strncat(fcontent, line, strlen(line));
		}
	}
	fclose(in);

	char* command = NULL;
	char* token = NULL;
	n = 0;
	char* fcopy = (char*)malloc((strlen(fcontent)+1)*sizeof(char));
	strcpy(fcopy, fcontent);
	command = strtok(fcopy, "\r\n");
	while (command != NULL){
		n++;
		command = strtok(NULL, "\r\n");
	}
	char* lines[n];
	command = NULL;
	int k = 0;
	command = strtok(fcontent, "\r\n");
	while (command != NULL){
		lines[k] = malloc(sizeof(command)*sizeof(char));
		strcpy(lines[k], command);
		k++;
		command = strtok(NULL, "\r\n");
	}

	for (int i = 0; i < n; i++){
		int l = 0;
		token = strtok(lines[i], ",");
		while (token != NULL){
			max[i][l] = atol(token);
			l++;
			token = strtok(NULL, ",");
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			allo[i][j] = 0;
			need[i][j] = max[i][j];
		}
	}
	printf("Number of Customers: %d\n", n);
	printf("Currently Available resources: ");
	for (int i = 0; i < m; i++){
		printf(" %d", ava[i]);
	}
	printf("\n");
	printf("Maximum resources from file:");
	for (int i = 0; i < n; i++){
		printf("\n");
		for (int j = 0; j < m; j++){
			printf("%d ", max[i][j]);
		}
	}
	printf("\n");
	char input[20];
	pthread_t workers[n];
	while (1){
		int index;
		int rq[m], rl[m];
		printf("Enter Command: ");
		scanf("%s", input);
		if (strcmp(input, "Status") == 0){
			show();
		}else if (strcmp(input, "Run") == 0){
			printf("Safe Sequence is:");
			IsSafe();
			for (int i = 0; i < n; i++){
				printf(" %d", safe[i]);
			}
			printf("\n");
			for (int i = 0; i < n; i++){
				pthread_create(&workers[i], NULL, threadRun, &safe[i]);
				sleep(3);
			}
			for (int i = 0; i < n; i++){
				pthread_join(workers[i], NULL);
			}
		}else if (strcmp(input, "Exit") == 0){
			break;
		}else if (strcmp(input, "RQ") == 0){
			scanf("%s", input);
			index = atol(input);
			for (int i = 0; i < m; i++){
				scanf("%s", input);
				rq[i] = atol(input);
			}
			Request(index, rq);
			if (IsSafe() == true){
				printf("State is safe, and request is satisfied");
			}else{
				Release(index, rq);
			}
		}else if (strcmp(input, "RL") == 0){
			scanf("%s", input);
			index = atol(input);
			for (int i = 0; i < m; i++){
				scanf("%s", input);
				rl[i] = atol(input);
			}
			Release(index, rl);
		}else{
			printf("Can't read your command, please try again\n");
		}
	}
	return 0;
}

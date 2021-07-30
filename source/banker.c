#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string>
#include <sys/stat.h>
#include <stdbool.h>

void* threadRun(void* t);
void IsSafe();

int main(int argc, char* argv[]){
	if (argc == 0){
		printf("Input file name missing...exiting with error code -1\n");
		return -1;
	}

	int m = argc - 1;
	int ava[m];
	for (int i = 0; i < m; i++){
		ava[i] = atol(argv[i+1]);
	}


	FILE *in = fopen("sample4_in.txt", "r");
	struct stat st;
	fstat(fileno(in), &st);
	char* fileContent = (char*)malloc(((int)st.st_size+1)*sizeof(char));
	fileContent[0] = '\0';
	while (!feof(in)){
		char line[50];
		if (fgets(line, 50, in) != NULL){
			strncat(fileContent, line, strlen(line));
		}
	}
	fclose(in);

	char* command = NULL;
	char* token = NULL;
	int n = 0;
	char* fcopy = (char*)malloc((strlen(fileContent)+1)*sizeof(char));
	strcpy(fcopy, fileContent);
	command = strtok(fcopy, "\r\n");
	while (command != NULL){
		n++;
		command = strtok(NULL, "\r\n");
	}
	int max[n][m];
	char* lines[n];
	command = NULL;
	int k = 0;
	command = strtok(fileContent, "\r\n");
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

	int allo[n][m];
	int need[n][m];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			allo[i][j] = 0;
			need[i][j] = max[i][j];
		}
	}
	printf("Number of Customers: %d\n");
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
	char* input;
	while (true){
		printf("Enter Command: ");
		scanf("%s ", &input);
	}
	return 0;
}

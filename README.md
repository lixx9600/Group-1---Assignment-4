# Assignment4 - group 1

Author: Runze Fan

student id: 180675430

Contributor: Wei Li

student id: 183309600

---

# Motivation

This program is intended to provide a safe algorithm for banks to interact with customers. Customers request and release resources from the bank. The banker will keep track of the resources. The banker will grant a request if it satisfies the safety algorithm. If a request does not leave the system in a safe state, the banker will deny it.

---

# Installation

This program is compiled with the eclipse compiler and tested and run under the Linux system environment using the VirtualBox virtual machine.

---

# Screenshots

IsSafe() implements the detection function. Check whether all threads are currently in safe status.

![image-20210801105737719](https://user-images.githubusercontent.com/88213120/127758657-43595bca-04db-4dc0-a808-9c5d9aca3840.png)

Request() implements the thread (ie, the customer) requesting resources from the bank. The banker will grant a request if it satisfies the safety algorithm. If a request does not leave the system in a safe state, the banker will deny it.

![image-20210801112718892](https://user-images.githubusercontent.com/88213120/127758675-31fccbe6-fe55-44df-9b0f-fb08b66caf2e.png)

---

# Individual contribution

The two developers cooperated in the discussion and negotiation to complete this program. 

Wei Li writes main() and threadRun()

Runze Fan writes IsSafe(), show(), Request(), and Release()

---

# Features

This program is characterized by stable operation and error-free operation, ensuring the safety of bank customersâ€™ assets.

---

# Tests cases

![image-20210801113212263](https://user-images.githubusercontent.com/88213120/127758681-3b1cfa17-85c7-4884-bf3e-8a66fc372478.png)

![image-20210801113326908](https://user-images.githubusercontent.com/88213120/127758683-59cb3b3e-fde3-4962-bd68-1b39d68fff4b.png)

![image-20210801113358358](https://user-images.githubusercontent.com/88213120/127758687-8d39f327-95ee-4331-81f1-af2ef9153540.png)

![image-20210801113439390](https://user-images.githubusercontent.com/88213120/127758693-84270c9c-e00f-49bd-94f1-ad91bf8ca13a.png)

---

# use examples

<RQ  [int customer_number]  [int Resource1]  [int Resource2]  ...  [int Resource4]>

<RL [int  customer_number]  [int Resource1]  [int Resource2]  ...  [int Resource4]>

<Status\>

<Run\>

<Exit\>

---

# About Developers

Wei Li: a programming genius, very good at CS go.

Runze Fan: a good student with a kind character

---

# Credits

Dr. Sukhjit Singh Sehra

---

# License

MIT

---

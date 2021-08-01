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

![image-20210801105737719](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801105737719.png)

Request() implements the thread (ie, the customer) requesting resources from the bank. The banker will grant a request if it satisfies the safety algorithm. If a request does not leave the system in a safe state, the banker will deny it.

![image-20210801112718892](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801112718892.png)

---

# Individual contribution

The two developers cooperated in the discussion and negotiation to complete this program. 

Wei Li writes main() and threadRun()

Runze Fan writes IsSafe(), show(), Request(), and Release()

---

# Features

This program is characterized by stable operation and error-free operation, ensuring the safety of bank customers’ assets.

---

# Tests cases

![image-20210801113212263](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801113212263.png)

![image-20210801113326908](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801113326908.png)

![image-20210801113358358](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801113358358.png)

![image-20210801113439390](C:\Users\runze\AppData\Roaming\Typora\typora-user-images\image-20210801113439390.png)

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

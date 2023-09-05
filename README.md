# Password Handler

Password Handler is a C language project that allows you to securely store passwords in encrypted form within a text file and provides functionality to retrieve 
passwords and display the names of websites that are present in text file in a sorted manner. It utilizes a static library for encryption and sorting operations. While running the program it also ask for authentication, so that security of the password can be ensured. 

## Need of Password Handler and Story behind making this project

As we all know that in today's world we make hundreds of digial accounts on different platforms and we have to remember them. But it is difficult to remember hundreds of different passwords. And also we can't use same password for every website we sign up because if anybody gets the password of one site then he or she has access of all the websites you have signed up with same password. By using this password handler you are able to store your passwords on one place. Moreover, the security of your passwords are ensured in two way that are, first any one using this application firstly have to authenticate and then he or she can access the passwords. Second the passwords of websites are stored in COMPLEX encrypted form. 

## Features

- Store passwords in an encrypted format in a text file.
- Retrieve and decrypt passwords from the text file.
- Display the list of stored websites in sorted order.
- Utilizes a static library for encryption and decryption operations.
- Utilizes a static library for sorting purpose.
- Encryption is in complex way.
- Authentication needed before using the application.

## Installation

1. Clone the repository:

$ git clone https://github.com/your-username/password-handler.git
$ cd password-handler

2. Build the project:

$ gcc -c main.c -o main.o
$ gcc -c lib-encrypt.c -o encrypt.c
$ ar rcs encrypt.a encrypt.c
$ gcc -o main main.o -L. encrypt.a

## Contributing

We welcome contributions to improve the project! To contribute, follow these steps:

1. Fork the repository and create a new branch.
2. Make your changes, whether bug fixes or new features.
3. Test thoroughly.
4. Commit your changes with descriptive commit messages.
5. Push your changes to your forked repository.
6. Open a pull request to the main repository.

## Acknowledgements

The encryption and sorting libraries used in this project are based on [encryption-lib] and [sorting-lib], respectively. We thank these projects for their valuable contributions.

---

Feel free to customize this README template to provide more details about your project and its usage. Providing clear instructions and explanations will help users understand how to use your password handler effectively.
```

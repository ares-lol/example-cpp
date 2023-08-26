# Example
A C++ example for Ares.lol using RSA asymmetrical encryption.

# Library
Our library for this is quite big and Github LFS is acting up, but you can download it at

[api.ares.lol/lib](https://api.ares.lol/lib)

# Encryption
To provide the best security we use asymmetrical encryption with RSA-4096

The client generates a public key/private key pair; then, it encrypts a message containing its public key using the server's public key. The server then decrypts that using its private key and responds with a message encrypted using the client's public key.

![Alice and Bob example](https://bjc.edc.org/March2019/bjc-r/img/3-lists/525px-Public_key_encryption.png)

# Streaming
If you want to stream simply call the `module` function on an authenticated `session_ctx` object.
```
ares::secure_image_ctx image_ctx = session_ctx.module("a590b336-ff74-477b-9564-93ba8d30118e");

std::vector<std::uint32_t> decrypted_image = image_ctx.decrypt();

// Work with the image

decrypted_image.clear();
```

# Variables
To get a variable simply call the `variable` function on an authenticated `session_ctx` object.
```
auto variable_name = skCrypt("var_1");

std::string variable = session_ctx.variable(variable_name.decrypt());
variable_name.clear();

std::printf("Variable: %s\n", variable.c_str());

variable.clear();
```

# Ares.lol
Ares.lol is a authentication system with a focus on security and quality.
[Check it out](https://ares.lol)
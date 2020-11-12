# MyEcho

## 项目简介

一直以来，想写一个简单的HTTP Server，但奈何自己菜。APUE、UNP、TCP/IP都还没学过，只能先参考着CSAPP上的echo服务器，写了这样一个Echo服务器。

- 用C++实现，并使用了部分C++11特性。
- 客户端发送小写字符串，服务器将其转为大写并回送给客户端。

不足之处：

- 基本上是用带类的C来实现，没有充分使用C++，C++和C混为一谈。
- C++11特性没有充分使用，只使用了最简单的一点内容。

## 使用方法

1. clone repo

   ```shell
   git clone https://github.com/xgx127/MyEcho.git
   ```

2. 构建项目

   ```shell
   cd MyEcho
   ./build.sh
   ```

3. 开启服务端

   ```shell
   cd bin
   ./server <Server Port ID>
   ```

4. 开启客户端

   ```shell
   ./client <Server IP Address> <Server Port ID>
   ```

5. 在客户端输入小写字符，回车，可看到服务端将其转为大写并回送。服务端显示每次传输的字节数。


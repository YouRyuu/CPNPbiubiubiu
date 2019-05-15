# 客户端
* 注册
* 登录
* 添加好友
* 查看好友列表
* 发送信息
* 接收信息
* 好友离线/在线状态转换
# 服务端
* 处理注册
* 处理登录
* 回射客户端之间的消息传递
* 处理用户间的动态变化
# 数据结构定义
```
typedef struct msgBody{     //定义消息体
    int type;       //消息类型:0.注册消息MSG_REG, 1.登录消息MSG_LOGIN, 2.退出消息MSG_EXIT, 3.一对一聊天MSG_CHAT, 4.管理员广播MSG_ADMIN
    int senderid;       //发送者id
    int recverid;       //接受者id,10000代表服务器
    char content[1024];     //消息正文
}
```
# 处理流程
* 登录   
登录的时候通过传递一个结构体字符串给服务器来验证用户口令是否正确以及在数据库中看用户是否已经登录   

    ```
    msgBody:type=1, senderid=senderid, recverid=10000, content=password
    ```       
    如果验证成功,服务器返回成功状态码同时记录IP,客户端跳转到使用界面;反之若验证失败,回射失败信息
* 注册   
注册的时候同样也传递一个结构体字符串,根据结构体中的信息来完成注册:
    ```
    typedef struct msgReg{
        msgBody msgBody;
        char password[50];
    }
    msgBody:type=0, senderid=0, recverid=10000, content=username, password=password;     
    ```
    如果验证成功,分配一个随机的uid,服务器返回成功注册状态码,客户端转到登录界面
* 添加好友   
用户通过输入uid的方式搜索好友,客户端发送客户uid+搜索uid到服务端,服务端验证信息存在与否和信息正确性将信息更新
* 发送消息    
用户发送消息:客户端将客户uid,消息接受者uid和消息正文发送至服务端
    ```
    type=3, senderid=senderid, recverid=recverid, content=content
    ```
    服务端再将消息转发至接收者
* 接收消息   
客户端接收到来自服务端的消息结构体信息并处理输出
* 查看好友列表    
服务端向客户端推送用户好友详情,客户端接收并处理
    ```
    typedef struct getList{
        msgBody msgBody;
        int friendsid[50];      //好友的id
        char *fridendsname[50];     //好友的昵称
    }
    type=4, senderid=10000, recverid=clientid, content="获取好友列表", friendsid=好友id, frientsname=好友昵称  一一对应
    ```
# 数据库设计
* 用户表
* 在线用户表
* 消息记录表
* 用户登录记录表
* 用户好友关系表
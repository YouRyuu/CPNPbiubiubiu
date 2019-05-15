高并发服务器    
  
  Q:端口65535个,为什么能够做到百万连接?  
  A:每一个连接是由一个五元组构成的:(remote ip, remote port, local ip, local port, protocol[tcp/udp])  
  Linux内核参数调优化->tcp协议栈调优化->send/recv buffer:  
  net.ipv4.tcp_wmem(write, 表示send buff)    net.ipv4.tcp_rmem(read, 表示recv buff)    fs.file-max   net.nf_conntrack_max  
  buffer大小根据服务器业务具体功能决定  
  每一个fd(int fd=socket(),最大值为65535)对应一个五元组  
  TCP/IP协议栈:从用户态开始
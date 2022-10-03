%% initialization script for tello takeoff
% open udp socket for communication with Tello drone (sim AND real)
u_lb = udp('127.0.0.1',    8889);
u_dr = udp('192.168.10.1', 8889);
fopen(u_lb);
fopen(u_dr);
% send command to get tello ready to receive commands
fwrite(u_lb,'command');
fwrite(u_dr,'command');
% send command to takeoff
fwrite(u_lb,'takeoff');
fwrite(u_dr,'takeoff');
% send command to request video stream
fwrite(u_lb,'streamon');
fwrite(u_dr,'streamon');
% close socket so that simulink or other software can use it
clear u_lb;
clear u_dr;

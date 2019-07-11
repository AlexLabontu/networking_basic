start Netsh advfirewall firewall add rule name="server" program=%~dp0server.exe protocol=tcp dir=in enable=yes action=allow localport=55555

exit
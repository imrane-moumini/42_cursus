#!bin/bash
Architecture=$(uname -a)
CPU_physical=$(cat /proc/cpuinfo | grep 'physical id' | uniq | wc -l)
vCPU=$(cat /proc/cpuinfo | grep 'processor' | uniq | wc -l)
Memory_used=$(free -h | grep 'Mem' | awk '{print $3}' )
Memory_total=$(free -h | grep 'Mem' | awk '{print $2}' )
memory_used_pourcentage=$(free -h | grep 'Mem' | awk '{print (($3/$2)*100)}')
Disk_used=$(df -h --total | grep 'total' | awk '{print $3}')
Disk_total=$(df -h --total | grep 'total' | awk '{print $2}')
Disk_Used_pourcentage=$(df -h --total | grep 'total' | awk '{print $5}')
CPU_load=$(top -n1 | grep '%Cpu' | awk '{print(100 - $8)}')
Last_boot_date=$(who -b | awk '{print $3}' )
Last_boot_hour=$(who -b | awk '{print $4}' )
LVM_use=$(if [ $(lsblk | grep 'lvm' | wc -l) -eq 0 ]; then echo 'no' ;else echo 'yes'; fi)
Connexions_TCP=$(grep 'TCP' /proc/net/sockstat | awk '{print $3}')
User_log=$(who | wc -l)
IP=$(hostname -I | awk '{print $1}')
MAC=$(ip link show | grep 'ether' | awk '{print $2}')
Sudo=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

wall "
echo 'Architecture: $Architecture '
echo 'CPU physical : $CPU_physical'
echo 'vCPU : $vCPU'
echo 'Memory Usage: $Memory_used / $Memory_total ( $memory_used_pourcentage % )'
echo 'Disk Usage: $Disk_used / $Disk_total ( $Disk_Used_pourcentage %)'
echo 'CPU load: $CPU_load %'
echo 'Last boot: $Last_boot_date $Last_boot_hour'
echo 'LVM use: $LVM_use'
echo 'Connexions TCP : $Connexions_TCP ESTABLISHED'
echo 'User log: $User_log'
echo 'Network: $IP ($MAC)'
echo 'Sudo : $Sudo' "
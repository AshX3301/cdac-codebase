cmd_/home/cdac-admin/Desktop/Ashwin_drivers/count/modules.order := {   echo /home/cdac-admin/Desktop/Ashwin_drivers/count/exp.ko;   echo /home/cdac-admin/Desktop/Ashwin_drivers/count/count.ko; :; } | awk '!x[$$0]++' - > /home/cdac-admin/Desktop/Ashwin_drivers/count/modules.order

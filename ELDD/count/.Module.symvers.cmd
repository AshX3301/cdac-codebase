cmd_/home/cdac-admin/Desktop/Ashwin_drivers/count/Module.symvers := sed 's/\.ko$$/\.o/' /home/cdac-admin/Desktop/Ashwin_drivers/count/modules.order | scripts/mod/modpost -m -a  -o /home/cdac-admin/Desktop/Ashwin_drivers/count/Module.symvers -e -i Module.symvers   -T -

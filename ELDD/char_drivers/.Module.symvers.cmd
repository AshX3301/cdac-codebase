cmd_/home/cdac-admin/Desktop/Ashwin_drivers/char_drivers/Module.symvers := sed 's/\.ko$$/\.o/' /home/cdac-admin/Desktop/Ashwin_drivers/char_drivers/modules.order | scripts/mod/modpost -m -a  -o /home/cdac-admin/Desktop/Ashwin_drivers/char_drivers/Module.symvers -e -i Module.symvers   -T -
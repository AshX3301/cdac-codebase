#define MAGIC 3
#define CMD_1 _IO(MAGIC,1)
#define CMD_2 _IOR(MAGIC,2,int)
#define CMD_3 _IOW(MAGIC,3,int)

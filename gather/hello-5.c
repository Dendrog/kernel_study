 /*
  * hello-5.c - 모듈에 명령줄 인수를 전달하는 방법을 시연.
  */
 #include <linux/init.h>
 #include <linux/kernel.h> /* for ARRAY_SIZE() */
 #include <linux/module.h>
 #include <linux/moduleparam.h>
 #include <linux/printk.h>
 #include <linux/stat.h>

 MODULE_LICENSE("GPL");

 static short int myshort = 1;
 static int myint = 420;
 static long int mylong = 9999;
 static char *mystring = "blah";
 static int myintarray[2] = { 420, 420 };
 static int arr_argc = 0;

 /* module_param(foo, int, 0000)
  * 첫 번째 매개변수는 매개변수 이름입니다.
  * 두 번째 매개변수는 데이터 유형입니다.
  * 마지막 인수는 나중에 sysfs에 매개변수를 노출하기 위한
  * 사용 권한 비트(0이 아닌 경우)입니다.
  */
 module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
 MODULE_PARM_DESC(myshort, "A short integer");
 module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
 MODULE_PARM_DESC(myint, "An integer");
 module_param(mylong, long, S_IRUSR);
 MODULE_PARM_DESC(mylong, "A long integer");
 module_param(mystring, charp, 0000);
 MODULE_PARM_DESC(mystring, "A character string");

 /* module_param_array(name, type, num, perm);
  * 첫 번째 매개변수는 매개변수(이 경우 배열)의 이름입니다.
  * 두 번째 매개변수는 배열 요소의 데이터 유형입니다.
  * 세 번째 인수는 모듈 로딩 시 사용자가 초기화한 배열의 요소 개수를
  * 저장할 변수에 대한 포인터입니다.
  * 네 번째 인수는 권한 비트입니다.
  */
 module_param_array(myintarray, int, &arr_argc, 0000);
 MODULE_PARM_DESC(myintarray, "An array of integers");

 static int __init hello_5_init(void)
 {
     int i;

     pr_info("Hello, world 5\n=============\n");
     pr_info("myshort is a short integer: %hd\n", myshort);
     pr_info("myint is an integer: %d\n", myint);
     pr_info("mylong is a long integer: %ld\n", mylong);
     pr_info("mystring is a string: %s\n", mystring);

     for (i = 0; i < ARRAY_SIZE(myintarray); i++)
         pr_info("myintarray[%d] = %d\n", i, myintarray[i]);

     pr_info("got %d arguments for myintarray.\n", arr_argc);
     return 0;
 }

 static void __exit hello_5_exit(void)
 {
     pr_info("Goodbye, world 5\n");
 }

 module_init(hello_5_init);
 module_exit(hello_5_exit);

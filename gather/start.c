 /*
  * start.c - 다중 파일 모듈을 묘사
  */

 #include <linux/kernel.h> /* 우리는 커널 작업을 하고 있음 */
 #include <linux/module.h> /* 구체적으로는 모듈을 다룸 */

 int init_module(void)
 {
     pr_info("Hello, world - this is the kernel speaking\n");
     return 0;
 }

 MODULE_LICENSE("GPL");

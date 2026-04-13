 /*
  * hello-1.c - 가장 단순한 커널 모듈.
  */
 #include <linux/module.h> /* 모든 모듈에 필요 */
 #include <linux/printk.h> /* pr_info()에 필요 */

 int init_module(void)
 {
     pr_info("Hello world 1.\n");

     /* 0이 아닌 반환값은 init_module이 실패했음을 의미하며, 모듈을 로드할 수 없습니다. */
     return 0;
 }

 void cleanup_module(void)
 {
     pr_info("Goodbye world 1.\n");
 }

 MODULE_LICENSE("GPL");
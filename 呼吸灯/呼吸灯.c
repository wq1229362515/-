   #include<reg51.h> 
void Delay1(int del)
{
        int i,j;
        for(i=0; i<del; i++)
        for(j=0; j<1827; j++)   
        ;
}
void Delay(unsigned int t)
{
 while(--t);
}

void LedBreath(){
	
     unsigned int CYCLE=400,PWM_LOW=0;//定义周期并赋值	   
        while (1)         //主循环
        {
/*--------整排LED灯呼吸---------*/
               if(IE1==1){
			  	 return;
			   } 
			   else{
			   	Delay1(100);                                                                 //加延时，可以看到熄灭的过程（下面程序同理）
                for(PWM_LOW=1;PWM_LOW<CYCLE;PWM_LOW++)           //PWM_LOW表示低
                        { 
                                P2=0x00;                                        
                                Delay(PWM_LOW);
                                P2=0xff; 
                                Delay(CYCLE-PWM_LOW);
                        }
                P1=0xff;                                                                                
                for(PWM_LOW=CYCLE-1;PWM_LOW>0;PWM_LOW--)         //与逐渐变亮相反的过程
                        {
                                   P2=0x00;                                                        //点亮LED 
                                   Delay(PWM_LOW);
                                   P2=0xff;                                                        //熄灭LED
                                  Delay(CYCLE-PWM_LOW);                                //主循环中添加其他需要一直工作的程序，延时长度，600次循环中从599减至1
                        }	   
			  }
		}
}

void LedShaing(){
	while(1) {
		if(IE0 == 1) {
			return; 
		}
		P2 = 0xff;
	 }
//P2 = 0xff;

	
}
void Init_Interrupt() {
	EA = 1;

	EX0 = 1;
//	EX0=0;		//外部中断0使能
	IE0 = 0;

	EX1 = 1;		//外部中断1使能
	IE1 = 0;

}

//中断程序
void interrupt_LedBreath() interrupt 0 {
	  IE0 = 0;
	  LedBreath();
}  

void interrupt_LedShaing() interrupt 2 {
	  IE1 = 0;
	  LedShaing();
}  

 //函数声明
unsigned int z,y;
void main (void)//主函数

{
	P2 = 0x00;
	//初始化中断,外部中断0
	Init_Interrupt();
	while(1);
}

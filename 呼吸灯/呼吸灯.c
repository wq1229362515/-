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
	
     unsigned int CYCLE=400,PWM_LOW=0;//�������ڲ���ֵ	   
        while (1)         //��ѭ��
        {
/*--------����LED�ƺ���---------*/
               if(IE1==1){
			  	 return;
			   } 
			   else{
			   	Delay1(100);                                                                 //����ʱ�����Կ���Ϩ��Ĺ��̣��������ͬ��
                for(PWM_LOW=1;PWM_LOW<CYCLE;PWM_LOW++)           //PWM_LOW��ʾ��
                        { 
                                P2=0x00;                                        
                                Delay(PWM_LOW);
                                P2=0xff; 
                                Delay(CYCLE-PWM_LOW);
                        }
                P1=0xff;                                                                                
                for(PWM_LOW=CYCLE-1;PWM_LOW>0;PWM_LOW--)         //���𽥱����෴�Ĺ���
                        {
                                   P2=0x00;                                                        //����LED 
                                   Delay(PWM_LOW);
                                   P2=0xff;                                                        //Ϩ��LED
                                  Delay(CYCLE-PWM_LOW);                                //��ѭ�������������Ҫһֱ�����ĳ�����ʱ���ȣ�600��ѭ���д�599����1
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
//	EX0=0;		//�ⲿ�ж�0ʹ��
	IE0 = 0;

	EX1 = 1;		//�ⲿ�ж�1ʹ��
	IE1 = 0;

}

//�жϳ���
void interrupt_LedBreath() interrupt 0 {
	  IE0 = 0;
	  LedBreath();
}  

void interrupt_LedShaing() interrupt 2 {
	  IE1 = 0;
	  LedShaing();
}  

 //��������
unsigned int z,y;
void main (void)//������

{
	P2 = 0x00;
	//��ʼ���ж�,�ⲿ�ж�0
	Init_Interrupt();
	while(1);
}

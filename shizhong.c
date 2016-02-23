#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int 
uchar tabel1[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f,~0x40,~0x00};
uchar tabel2[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
uchar shi,fen,miao,ii,jj,d[8],dd[8],dd1[8],dd2[8],ts,naozhong,ns,nf,ns1,nf1,ns2,nf2,flag,bp,nflag,nflag1,nflag2,geflag,num2;
sbit key1=P1^4;
sbit key2=P1^5;
sbit key3=P1^6;
sbit key4=P1^7;
sbit beep=P3^7;
sbit wei1=P2^0;
sbit wei2=P2^1;
sbit wei3=P2^3;
sbit wei4=P2^4;
sbit wei5=P2^6;
sbit wei6=P2^7;

void delay(uint a)
{
	uint i;
	for(;a>0;a--)
	for(i=6245;i>0;i--);
}
void delay1(uint a)
{
	uchar i;
	for(;a>0;a--)
	for(i=19;i>0;i--);
}
void display()
{
	uchar i;
	d[0]=shi/10;
	d[1]=shi%10;
	d[2]=10;
	d[3]=fen/10;
	d[4]=fen%10;
	d[5]=10;
	d[6]=miao/10;
	d[7]=miao%10;

	dd[0]=ns/10;
	dd[1]=ns%10;
	dd[2]=10;
	dd[3]=nf/10;
	dd[4]=nf%10;
	dd[5]=11;
	dd[6]=bp;
	dd[7]=naozhong;

	dd1[0]=ns1/10;
	dd1[1]=ns1%10;
	dd1[2]=10;
	dd1[3]=nf1/10;
	dd1[4]=nf1%10;
	dd1[5]=11;
	dd1[6]=bp;
	dd1[7]=naozhong;

	dd2[0]=ns2/10;
	dd2[1]=ns2%10;
	dd2[2]=10;
	dd2[3]=nf2/10;
	dd2[4]=nf2%10;
	dd2[5]=11;
	dd2[6]=bp;
	dd2[7]=naozhong;
	for(i=0;i<8;i++)
	{
		if(naozhong==0)
		{
			P0=tabel1[d[i]];
			if((i==7)&&(bp==1))
			{
				P0=P0&0x7f;
			}
		}
		if(naozhong==1)
		{
			P0=tabel1[dd[i]];
		}
		if(naozhong==2)
		{
			P0=tabel1[dd1[i]];
		}
		if(naozhong==3)
		{
			P0=tabel1[dd2[i]];
		}
		P2=tabel2[i];
		if((ts==1)&&(flag==0))
		{
			wei1=1;
			wei2=1;
		}
		
		if((ts==2)&&(flag==0))
		{
			wei3=1;
			wei4=1;
		}
		if((ts==3)&&(flag==0))
		{
			wei5=1;
			wei6=1;
		}
		if((naozhong==1)&&((nflag==0)&&(flag==0))||((naozhong==2)&&(nflag1==0)&&(flag==0))||((naozhong==3)&&(nflag2==0)&&(flag==0)))
		{
			wei1=1;
			wei2=1;
		}
		if((naozhong==1)&&((nflag==1)&&(flag==0))||((naozhong==2)&&(nflag1==1)&&(flag==0))||((naozhong==3)&&(nflag2==1)&&(flag==0)))
		{
			wei3=1;
			wei4=1;
		}
		delay1(5);
		P2=0xff;
	}	
}

void key()
{
	if(naozhong==0)
	{
		if(key1==0)
		{
			delay1(10);
			if(key1==0)
			{
				
				ts++;
				
				if(ts==4)
				{
					ts=0;
				}
				if((ts==1)||(ts==2)||(ts==3))			
				{
					TR0=0;
				}
				while(!key1) display();	
			}
			delay1(10);
			while(!key1);
		}
		
		if(ts==0)
		{
			TR0=1;
			
		}
		if(ts==1)
		{
			if(key3==0)
			{
				delay1(10);
				if(key3==0)
				{
					shi++;
					if(shi==24)
					{
						shi=0;
					}
				}
			delay1(10);
			while(!key3)display();
			}
		}
		if(ts==2)
		{
			if(key3==0)
			{
				delay1(10);
				if(key3==0)
				{
					fen++;
					if(fen==60)
					{
						fen=0;
					}
				}
			delay1(10);
			while(!key3)display();
			}
		}
		if(ts==3)
		{
			if(key3==0)
			{
				delay1(10);
				if(key3==0)
				{
					miao++;
					if(miao==60)
					{
						miao=0;
					}
				}
			delay1(10);
			while(!key3)display();
			}
		}
	}
	if(key2==0)
	{
		delay1(10);
		if(key2==0)
		{
			bp++;
			if(bp==2)
			{
				bp=0;
			}
			while(!key2) display();
		}
		delay1(10);
		while(!key2);
	}
	if(ts==0)
	{
		if(key4==0)
		{
			delay1(10);
			if(key4==0)
			{
				
				naozhong++;
				if(naozhong==4)
				{
					naozhong=0;
				}
	
				while(!key4)display();
			}
			delay1(10);
			while(!key4);
		}
		
		if(naozhong==1)
		{	 
			if(key1==0)
			{
				delay1(10);
				if(key1==0)
				{
					nflag++;
					if(nflag==2)
					{
						nflag=0;
					}
				}
				while(!key1)display();
			}
			if(nflag==0)
			{
				 if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						ns++;
						if(ns==24)
						{
							ns=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
			if(nflag==1)
			{
				if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						nf++;
						if(nf==60)
						{
							nf=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
		}
		if(naozhong==2)
		{
			if(key1==0)
			{
				delay1(10);
				if(key1==0)
				{
					nflag1++;
					if(nflag1==2)
					{
						nflag1=0;
					}
				}
				while(!key1)display();
			}
			if(nflag1==0)
			{
				 if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						ns1++;
						if(ns1==24)
						{
							ns1=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
			if(nflag1==1)
			{
				if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						nf1++;
						if(nf1==60)
						{
							nf1=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
		}
		
		if(naozhong==3)
		{
			if(key1==0)
			{
				delay1(10);
				if(key1==0)
				{
					nflag2++;
					if(nflag2==2)
					{
						nflag2=0;
					}
				}
				while(!key1)display();
			}
			if(nflag2==0)
			{
				 if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						ns2++;
						if(ns2==24)
						{
							ns2=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
			if(nflag2==1)
			{
				if(key3==0)
				{
					delay1(10);
					if(key3==0)
					{
						nf2++;
						if(nf2==60)
						{
							nf2=0;
						}
					}
				delay1(10);
				while(!key3)display();
				}
			}
		}
	}	
}
void main()
{
	TMOD=0x11;
	TH0=(65536-46296)/256;
	TL0=(65536-46296)%256;
	TH1=(65536-46296)/256;
	TL1=(65536-46296)%256;
	EA=1;
	ET0=1;
	ET1=1;
	TR0=1;
	TR1=1;
	beep=1;
	shi=12;
	while(1)
	{
	   display();
	   key();
	   if(((geflag==0)&&(shi==ns)&&(fen==nf)&&(bp==1))||((geflag==0)&&(shi==ns1)&&(fen==nf1)&&(bp==1))||((geflag==0)&&(shi==ns2)&&(fen==nf2)&&(bp==1)))
	   {
	   		 beep=0;
			 delay1(50);
			 beep=1;
	   }

	}

}
void timer() interrupt 1
{
	TH0=(65536-46296)/256;
	TL0=(65536-46296)%256;
	jj++;
	
	if(jj==20)
	{
		jj=0;
		
		miao++;
	}
	if(miao==60)
	{
		miao=0;
		fen++;
	}
	if(fen==60)
	{
	 	fen=0;
		shi++;
	}
	if(shi==24)
	{
		shi=0;
	}
		
}
void timer1() interrupt 3
{
	TH1=(65536-46296)/256;
	TL1=(65536-46296)%256;
	ii++;
	num2++;
	if(ii==10)
	{
		ii=0;
		flag=~flag;
	}
	if(num2==5)
	{
		num2=0;
		geflag=~geflag;
	}
}
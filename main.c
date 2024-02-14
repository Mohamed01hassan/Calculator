#include"4-LIB/STD_TYPES.h"
#include"4-LIB/BIT_MATH.h"


#include"2-PORT/PORT_interface.h"
#include"CLCD/CLCD_interface.h"
#include"KeyPad/KPD_interface.h"
#include "1-DIO/DIO_interface.h"
#include"KeyPad/KPD_config.h"


f32 NUM(f32* , u8);

void main()
{

	PORT_voidInit();
	CLCD_voidIntialization();



	char Error[]={"ERROR"};



	while(1)
	{

		u32 Local_u32Remainder;
		u32 Local_f32NUM1;
		u32 Local_f32NUM2;
		u8 Local_u8NegativeSign1;		// for Number1 sign
		u8 Local_u8NegativeSign2;		// for Number2 sign
		u8 Local_u8NegativeSign3;
		f64 Local_f64Result;

		u8 Local_u8Arr1Size , Local_u8Arr2Size;	//Size of two Arrays
		u8 Local_u8Key;	//to the pressed key



		f32 Local_pf32Arr1[5];	//Array for first number
		f32 Local_pf32Arr2[5];	//Array for second number



		u8 Local_u8Iterator1=0;
		u8 Local_u8Iterator2=0;; // for iterations



		do
		{
			Local_u8Key=KPD_u8GetPressedKey();

			if (Local_u8Iterator1==0)
			{
				if(Local_u8Key==12)
				{
					CLCD_u8SendData('-');
					Local_u8NegativeSign1=1;
					Local_u8Key=KPD_NO_PRESSED_KEY;
				}

				else if (Local_u8Key>=0 && Local_u8Key<=9)
				{

					CLCD_voidWriteNumber(Local_u8Key);
					Local_pf32Arr1[Local_u8Iterator1]=Local_u8Key;
					Local_u8Iterator1++;
				}
			}
			else
			{
				if (Local_u8Key>=0 && Local_u8Key<=9)
				{

					CLCD_voidWriteNumber(Local_u8Key);
					Local_pf32Arr1[Local_u8Iterator1]=Local_u8Key;
					Local_u8Iterator1++;
				}

			}
		}while((Local_u8Key>=0 && Local_u8Key<=9)||Local_u8Key==KPD_NO_PRESSED_KEY);
		if(Local_u8NegativeSign1!=1)
		{
			Local_u8NegativeSign1=0;
		}

		Local_u8Arr1Size=Local_u8Iterator1;				//To identify size of array
		Local_f32NUM1=NUM(Local_pf32Arr1,Local_u8Arr1Size);

		switch (Local_u8Key)
		{

		case 16 :
			CLCD_u8SendData('+');
			do
			{
				Local_u8Key=KPD_u8GetPressedKey();


					if (Local_u8Key>=0 && Local_u8Key<=9)
					{

						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}


			}while(((Local_u8Key>=0 && Local_u8Key<=16) && (Local_u8Key!=13&& Local_u8Key!=15))||Local_u8Key==KPD_NO_PRESSED_KEY  );

			if(Local_u8NegativeSign2!=1)
			{
				Local_u8NegativeSign2=0;
			}

			Local_u8Arr2Size=Local_u8Iterator2;				//To identify size of array
			Local_f32NUM2=NUM(Local_pf32Arr2,Local_u8Arr2Size);

			if (Local_u8NegativeSign1==1 && Local_u8NegativeSign2==0)
			{
				if (Local_f32NUM1>Local_f32NUM2)
				{
					Local_u8NegativeSign3=0;
					Local_f64Result=Local_f32NUM1-Local_f32NUM2;
					Local_u8NegativeSign1=1;
				}
				else
				{
					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM2-Local_f32NUM1;
					Local_u8NegativeSign1=0;
					Local_u8NegativeSign2=1;
				}
			}
			else if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==0)
			{

				Local_u8NegativeSign3=0;
				Local_f64Result=Local_f32NUM1+Local_f32NUM2;
			}


			Local_u32Remainder=0;



			break;


		case 12 :
			CLCD_u8SendData('-');
			do
			{
				Local_u8Key=KPD_u8GetPressedKey();

				if (Local_u8Iterator2==0)
				{
					if(Local_u8Key==12)
					{
						CLCD_u8SendData('-');
						Local_u8NegativeSign2=1;
						Local_u8Key=KPD_NO_PRESSED_KEY;
					}

					else if (Local_u8Key>=0 && Local_u8Key<=9)
					{


						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}
				}
				else
				{
					if (Local_u8Key>=0 && Local_u8Key<=9)
					{

						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}

				}
			}while((Local_u8Key>=0 && Local_u8Key<=9)||Local_u8Key==KPD_NO_PRESSED_KEY);

			if(Local_u8NegativeSign2!=1)
			{
				Local_u8NegativeSign2=0;
			}

			Local_u8Arr2Size=Local_u8Iterator2;				//To identify size of array
			Local_f32NUM2=NUM(Local_pf32Arr2,Local_u8Arr2Size);
			if (Local_f32NUM1>Local_f32NUM2)
			{
				if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==0)
				{
					Local_u8NegativeSign3=0;
					Local_f64Result=Local_f32NUM1-Local_f32NUM2;
				}
				else if (Local_u8NegativeSign1==1 && Local_u8NegativeSign2==1)
				{
					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM1-Local_f32NUM2;
				}

				else if (Local_u8NegativeSign1==1 && Local_u8NegativeSign2==0)
				{
					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM1+Local_f32NUM2;
				}

				else if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==1)
				{

					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM1+Local_f32NUM2;
				}


			}
			else
			{

				if (Local_u8NegativeSign1==1 && Local_u8NegativeSign2==1)
				{
					Local_u8NegativeSign3=0;
					Local_f64Result=Local_f32NUM2-Local_f32NUM1;
				}

				else if (Local_u8NegativeSign1==1 && Local_u8NegativeSign2==0)
				{
					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM2+Local_f32NUM1;
				}
				else if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==1)
				{

					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM2+Local_f32NUM1;
				}
				else if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==0)
				{

					Local_u8NegativeSign3=1;
					Local_f64Result=Local_f32NUM2-Local_f32NUM1;
				}

			}
			Local_u32Remainder=0;
			break;

		case 11 :
			CLCD_u8SendData('x');
			do
			{
				Local_u8Key=KPD_u8GetPressedKey();

				if (Local_u8Iterator2==0)
				{
					if(Local_u8Key==12)
					{
						CLCD_u8SendData('-');
						Local_u8NegativeSign2=1;
						Local_u8Key=KPD_NO_PRESSED_KEY;
					}

					else if (Local_u8Key>=0 && Local_u8Key<=9)
					{


						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}
				}
				else
				{
					if (Local_u8Key>=0 && Local_u8Key<=9)
					{

						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}

				}
			}while((Local_u8Key>=0 && Local_u8Key<=9)||Local_u8Key==KPD_NO_PRESSED_KEY);

			if(Local_u8NegativeSign2!=1)
			{
				Local_u8NegativeSign2=0;
			}

			Local_u8Arr2Size=Local_u8Iterator2;				//To identify size of array
			Local_f32NUM2=NUM(Local_pf32Arr2,Local_u8Arr2Size);


			Local_u8NegativeSign3=0;

			Local_f64Result=Local_f32NUM1*Local_f32NUM2;
			Local_u32Remainder=0;
			break;

		case 10 :
			CLCD_u8SendData(0b11111101);    //code for ÷ from LCD datasheet
			do
			{
				Local_u8Key=KPD_u8GetPressedKey();

				if (Local_u8Iterator2==0)
				{
					if(Local_u8Key==12)
					{
						CLCD_u8SendData('-');
						Local_u8NegativeSign2=1;
						Local_u8Key=KPD_NO_PRESSED_KEY;
					}

					else if (Local_u8Key>=0 && Local_u8Key<=9)
					{


						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}
				}
				else
				{
					if (Local_u8Key>=0 && Local_u8Key<=9)
					{

						CLCD_voidWriteNumber(Local_u8Key);
						Local_pf32Arr2[Local_u8Iterator2]=Local_u8Key;
						Local_u8Iterator2++;
					}

				}
			}while((Local_u8Key>=0 && Local_u8Key<=9)||Local_u8Key==KPD_NO_PRESSED_KEY);

			if(Local_u8NegativeSign2!=1)
			{
				Local_u8NegativeSign2=0;
			}

			Local_u8Arr2Size=Local_u8Iterator2;				//To identify size of array
			Local_f32NUM2=NUM(Local_pf32Arr2,Local_u8Arr2Size);

			Local_u8NegativeSign3=0;

			Local_f64Result=Local_f32NUM1/Local_f32NUM2;
			Local_u32Remainder=((Local_f32NUM1 % Local_f32NUM2)*10)/Local_f32NUM2 ;




			break;

		case 13 :CLCD_u8SendCommand(0b00000001);break;


		}

		while(Local_u8Key!=15 && Local_u8Key!=13 )
		{

			Local_u8Key=KPD_u8GetPressedKey();
		}
		if (Local_u8Key==15)
		{

			if (Local_u8NegativeSign3==0)
			{
				if ((Local_u8NegativeSign1==1 && Local_u8NegativeSign2==1) ||(Local_u8NegativeSign1==0 && Local_u8NegativeSign2==0 ))

				{

					CLCD_u8GoToXY(1,4);
					CLCD_u8SendData('=');
					CLCD_voidWriteNumber(Local_f64Result);
					CLCD_u8SendData(0b00101110);	// code for dot
					CLCD_voidWriteNumber(Local_u32Remainder);

				}

				else if ((Local_u8NegativeSign1==1 && Local_u8NegativeSign2==0) || (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==1))

				{

					CLCD_u8GoToXY(1,4);
					CLCD_u8SendData('=');
					CLCD_u8SendData('-');
					CLCD_voidWriteNumber(Local_f64Result);
					CLCD_u8SendData(0b00101110);	// code for dot
					CLCD_voidWriteNumber(Local_u32Remainder);

				}


			}



			else if (Local_u8NegativeSign3==1)
			{
				if ((Local_u8NegativeSign1==1 && Local_u8NegativeSign2==1) ||(Local_u8NegativeSign1==0 && Local_u8NegativeSign2==0 ))

				{

					CLCD_u8GoToXY(1,4);
					CLCD_u8SendData('=');
					CLCD_u8SendData('-');
					CLCD_voidWriteNumber(Local_f64Result);
					CLCD_u8SendData(0b00101110);	// code for dot
					CLCD_voidWriteNumber(Local_u32Remainder);

				}

				else if (Local_u8NegativeSign1==0 && Local_u8NegativeSign2==1 )

				{

					CLCD_u8GoToXY(1,4);
					CLCD_u8SendData('=');
					CLCD_voidWriteNumber(Local_f64Result);
					CLCD_u8SendData(0b00101110);	// code for dot
					CLCD_voidWriteNumber(Local_u32Remainder);

				}
				else
				{

					CLCD_u8GoToXY(1,4);
					CLCD_u8SendData('=');
					CLCD_u8SendData('-');
					CLCD_voidWriteNumber(Local_f64Result);
					CLCD_u8SendData(0b00101110);	// code for dot
					CLCD_voidWriteNumber(Local_u32Remainder);
				}
			}

		}

		else if (Local_u8Key==13)
		{
			CLCD_u8SendCommand(0b00000001);
		}

		Local_u8NegativeSign1=0;
		Local_u8NegativeSign2=0;
		Local_u8NegativeSign3=0;



	}
}
f32 NUM(f32* Arr, u8 size)
{
	u8 Local_u8Iterator1;
	u8 Local_u8Iterator2;
	u8 Local_u8Iterator3;
	f32 Local_u8Num=0;
	for(Local_u8Iterator1=0;Local_u8Iterator1<size-1;Local_u8Iterator1++)
	{
		for (Local_u8Iterator2=1;Local_u8Iterator2<size-Local_u8Iterator1;Local_u8Iterator2++)
		{
			Arr[Local_u8Iterator1]=Arr[Local_u8Iterator1]*10;
		}
	}

	for (Local_u8Iterator3=0;Local_u8Iterator3<size;Local_u8Iterator3++)
	{

		Local_u8Num=Local_u8Num+Arr[Local_u8Iterator3];

	}
	return Local_u8Num;
}



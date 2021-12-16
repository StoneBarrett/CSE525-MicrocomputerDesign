//Team 7
//Project 1 Part 1
//Compile on Raspberry Pi with gcc to make sure there are no errors (gcc P1-1.c)
//Generate assembly listing (gcc -S P1-1.c)
//Fullfill part 1 requirements in generated assembly file

//Global Data Types
signed char var1 =1;
unsigned char var2 = 2;
signed int var3 =3;
unsigned int var4 = 4;
const int num =-10;
char wave[10]="goodbye!!!";

void main(){
	//Local data types
	int var5 =5;

	//Loop types
	for(var5;var5>0;var5--){
		var1*=var1;
		var1/=var1;
		var1+=var1;
		var1-=var1;
	}

	do{
	var4-=1;
	}while(var4>0);

	while(var3 ==3){
	var2=var2;
	break;
	}
}


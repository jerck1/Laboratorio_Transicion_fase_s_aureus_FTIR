
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "fstream"
#include "string"
#include<iomanip>//para manipular el setw
using namespace std;
double Promedio(double A[],int n){
	double xbar=0;
	for (int i=0;i<n;i++)
		xbar+=A[i];
	return xbar/n;
}
double Desviacion(double A[],int n){
	double s=0;
	double p;	
	p=Promedio(A,n);
	for (int i=0;i<n;i++)
		s+=(A[i]-p)*(A[i]-p);
	s=sqrt(s/(n-1));
	return s;
}
int main(){
ifstream miFichero("datos_santa.csv");
int m=349, n=4;
double A[m][4], pro[3];
int cont[]={0,0,0};
//Es como un cin miFichero>>A[i][j];
for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                miFichero>>A[i][j];
		//cout<<A[i][j]<<" ";
		}
//cout<<endl;
	}
//Se cierra el archivo porque sino se puede danar
miFichero.close();
//Enviar info a un archivo plano
//off file stream
ofstream miFichero2;
ofstream miFichero3;
ofstream miFichero4;
//Ficheros donde se guardan los datos separados
miFichero2.open("curva_144.csv");
miFichero3.open("curva_145.csv");
miFichero4.open("curva_147.csv");

//setw(): reserva para cada dato 10 lugares
for(int i=0;i<m;i++){
	if(A[i][1]==144){
		if(cont[0]==0){
        		for(int j=0;j<n;j++)
				pro[0]=A[i][2];
		}
		cont[0]++;
		A[i][2]=A[i][2]-pro[0];
        	for(int j=0;j<n;j++)
                	miFichero2<<setw(11)<<A[i][j]<<"\t";
		miFichero2<<endl;
	}
	if(A[i][1]==145){
		if(cont[1]==0){
        		for(int j=0;j<n;j++)
				pro[1]=A[i][2];
		}
		cont[1]++;

		A[i][2]=A[i][2]-pro[1];
        	for(int j=0;j<n;j++)
                	miFichero3<<setw(11)<<A[i][j]<<"\t";
		miFichero3<<endl;
	}
	if(A[i][1]==147){
		if(cont[2]==0){
        		for(int j=0;j<n;j++)
				pro[2]=A[i][2];
		}
		cont[2]++;

		A[i][2]=A[i][2]-pro[2];
        	for(int j=0;j<n;j++)
                	miFichero4<<setw(11)<<A[i][j]<<"\t";
		miFichero4<<endl;
	}
        }
////////////////////////////////////////////////////////////////////////////
//Promediamos los datos
ifstream miFichero5("curva_144.csv");
ifstream miFichero6("curva_145.csv");
ifstream miFichero7("curva_147.csv");
//Ficheros con datos separados y promediados si estan a menos de 10 min
ofstream miFichero8;
ofstream miFichero9;
ofstream miFichero10;
miFichero8.open("curva_144prom.csv");
miFichero9.open("curva_145prom.csv");
miFichero10.open("curva_147prom.csv");
//donde se guardan los datos de cada curva
double B[cont[0]][4], C[cont[1]][4], D[cont[2]][4];
double h=1/6.;
double b[4],c[4],d[4];
double b2[4],c2[4],d2[4];
int con2=0;
double xbar;
double xbar2;
double s;
double s2;
//for(int i=0;i<cont[0];i++){
//for(int j=0;j<n;j++){
//	miFichero5>>B[i][j];
//	cout<<B[i][j]<<"\t";
//}
//cout<<endl;
//}
for(int j=0;j<n;j++){
	miFichero5>>B[0][j];
	cout<<B[0][j]<<"\t";
}

for(int i=1;i<cont[0];i++){
        for(int j=0;j<n;j++){
                miFichero5>>B[i][j];		
		}
	if((abs(B[i-1][2]-B[i][2])<h)&&(con2<5)){
		b[con2]=B[i][2];
		b2[con2]=B[i][3];
		con2++;
//		cout<<"a"<<b[con2[0]];
	}
	if(con2==4){
		con2=0;
		xbar=Promedio(b,n);
		xbar2=Promedio(b2,n);
		s=Desviacion(b,n);
		s2=Desviacion(b2,n);
		for(int k=0;k<3;k++){
			miFichero8<<xbar<<","<<xbar2<<","<<s<<","<<s2<<endl;
//			miFichero8<<Promedio(b,n)<<","<<Promedio(b2,n)<<","<<Desviacion(b,n)<<","<<Desviacion(b2,n)<<endl;
		}
	}
}
con2=0;
for(int j=0;j<n;j++){
	miFichero6>>C[0][j];
	cout<<C[0][j]<<"\t";
}

for(int i=1;i<cont[1];i++){
        for(int j=0;j<n;j++){
                miFichero6>>C[i][j];		
		}
	if((abs(C[i-1][2]-C[i][2])<h)&&(con2<5)){
		c[con2]=C[i][2];
		c2[con2]=C[i][3];
		con2++;
//		cout<<"a"<<b[con2[0]];
	}
	if(con2==4){
		con2=0;
		xbar=Promedio(c,n);
		xbar2=Promedio(c2,n);
		s=Desviacion(c,n);
		s2=Desviacion(c2,n);
		for(int k=0;k<3;k++){
			miFichero9<<xbar<<","<<xbar2<<","<<s<<","<<s2<<endl;
//			miFichero8<<Promedio(b,n)<<","<<Promedio(b2,n)<<","<<Desviacion(b,n)<<","<<Desviacion(b2,n)<<endl;
		}
	}
}
con2=0;
for(int j=0;j<n;j++){
	miFichero7>>D[0][j];
	cout<<D[0][j]<<"\t";
}

for(int i=1;i<cont[2];i++){
        for(int j=0;j<n;j++){
                miFichero7>>D[i][j];		
		}
	if((abs(D[i-1][2]-D[i][2])<h)&&(con2<5)){
		d[con2]=D[i][2];
		d2[con2]=D[i][3];
		con2++;
//		cout<<"a"<<b[con2[0]];
	}
	if(con2==4){
		con2=0;
		xbar=Promedio(d,n);
		xbar2=Promedio(d2,n);
		s=Desviacion(d,n);
		s2=Desviacion(d2,n);
		for(int k=0;k<3;k++){
			miFichero10<<xbar<<","<<xbar2<<","<<s<<","<<s2<<endl;
//			miFichero8<<Promedio(b,n)<<","<<Promedio(b2,n)<<","<<Desviacion(b,n)<<","<<Desviacion(b2,n)<<endl;
		}
	}
}





//for(int i=0;i<3;i++)
//	cout<<cont[i]<<" ";
miFichero2.close();
miFichero3.close();
miFichero4.close();
miFichero5.close();
miFichero6.close();
miFichero7.close();
miFichero8.close();
miFichero9.close();
miFichero10.close();

system("Pause");
return 0;
}

/*************************************************************************/
/*                    st_syst                                            */
/*                    =======                                            */
/*   Расчёт простой стержневой системы  по МКЭ                           */
/*************************************************************************/
#include <stdio.h>
#include <math.h>

#define ALL_SS       2     // число степеней свободы в задаче
#define KE_UZ_MAX    2     //  максимальное число узлов в КЭ
#define KE_FGEO_MAX  2     //  максимальное число физ. и геом характеристик

#define  DIM  sizeof(mcoor)/sizeof(mcoor[0])* ALL_SS // размерность глобальной 
                                                     // матрицы жескости 
                                                      

#define  DIM_RE  KE_UZ_MAX*ALL_SS  // размерность локальной матрицы жесткости

/*-------------------------------------*/
/*  БАЗОВЫЕ СТРУКТУРЫ ДАННЫХ           */
/*-------------------------------------*/
struct  INFO_KE { int type, all_uz, all_ss, all_fizgeo; };

                // тип   узлов  ст.свободы  физ-гео_характ
INFO_KE tab_ke[]= { {1 , 2 , 2 , 2 } // шарнирный стержень
				};


struct COOR { double x,y,z; };

struct TPL  { int tke, num[KE_UZ_MAX] , num_fizgeo; };

struct FIZGEO { double fgeo[KE_FGEO_MAX]; };

struct LINK   { int nu;
                char ss[ALL_SS+1];
               };
  
struct FORSE { int nu;
               double f[ALL_SS];
             };

/*-------------------------------------*/
/*         ИСХОДНЫЕ ДАННЫЕ             */
/*-------------------------------------*/

 COOR mcoor[]={ { 0, 0, 0 },
                { 1, 1, 0 }, 
                { 2, 0, 0 }
              };

 TPL  mtpl[]= { { 1, { 1, 2 } , 1 }, 
                { 1, { 2, 3 } , 1 }, 
                { 1, { 3, 1 } , 2 }
              };

 FIZGEO mfizgeo[]= { { 200, 1 } ,
                     { 200, 1 } 
                   }; 


 LINK  mlink[]= { { 1 , "11" },
                  { 3 , "01" }
                };


 FORSE mforse[]= { { 2 , { 0 , 1 } },
                   { 1 , { 0 , 0 } }
                 };



/*-------------------------------------*/
/*     УПРАВЛЯЮЩИЙ МОДУЛЬ              */
/*-------------------------------------*/

void re_st_2_2 ( TPL  , COOR [] , FIZGEO [] , double [DIM_RE][DIM_RE]);
void st_solve_gauss (int , double [DIM][DIM], double [], double []);
#include "st_solve_gauss.cpp"


void main(void)
{

 // Локальная матрица жёсткости
 double  re[DIM_RE][DIM_RE];

 // Глобальная матрица жёсткости
 double RGLOBAL[DIM][DIM],V_PCH[DIM],V_Z[DIM];

 int     mi[10],it,i,j,i1,j1,ind1,ind2,
	     indr1,indr2, nu,num,all_uz,type_ke,
	     all_ke  =sizeof(mtpl)/sizeof(mtpl[0]),
		 all_nag =sizeof(mforse)/sizeof(mforse[0]),
		 all_link=sizeof(mlink)/sizeof(mlink[0]); 

 
 for(i=0; i<DIM; i++)
 {
   V_PCH[i]=0.0;

   for(j=0; j<DIM; j++)
      RGLOBAL[i][j]=0.0;
 } 

 /*---------------------------------------------*/
 /*  ФОРМИРОВАНИЕ ГЛОБАЛЬНОЙ МАТРИЦЫ ЖЕСТКОСТИ  */
 /*---------------------------------------------*/
 for(it=0 ; it < all_ke ; it++)
 { 
    type_ke=mtpl[it].tke;
	all_uz =tab_ke[type_ke-1].all_uz;

	for(i=0 ; i< all_uz ; i++)
	{
      nu=mtpl[it].num[i]-1;
	  mi[i]=nu*ALL_SS;
	}	 
 
	switch (type_ke)
    {   
		// Плоский шарнирный стержень
		case 1:
			re_st_2_2 ( mtpl[it]  , mcoor ,  mfizgeo , re);
			break;

        default: break; 
    }
      
    for(i=0 ; i< all_uz ; i++)
	   for(j=0; j< all_uz ; j++)
         for(i1=0 ; i1 < ALL_SS ; i1++)
            for(j1=0 ; j1<ALL_SS ; j1++)
			{  
                ind1 =mi[i]+i1;        ind2 =mi[j]+j1; 
                indr1=i*ALL_SS+i1;     indr2=j*ALL_SS+j1; 

                RGLOBAL[ind1][ind2]+=re[indr1][indr2];                   
             }
 }
 /*---------------------------------------------*/
 /*  ФОРМИРОВАНИЕ ВЕКТОРА ПРАВОЙ ЧАСТИ          */
 /*---------------------------------------------*/

   for (i=0 ; i< all_nag ; i++)
   {
	  num=(mforse[i].nu-1)*ALL_SS;

      for(j=0; j<ALL_SS ; j++)
        V_PCH[num+j]=mforse[i].f[j];
   }
 /*---------------------------------------------*/
 /*       УЧЁТ  ГРАНИЧНЫХ УСЛОВИЙ               */
 /*---------------------------------------------*/

  for (i=0 ; i < all_link ; i++)
  {
    num=(mlink[i].nu-1)*ALL_SS;

    for(j=0; j<ALL_SS ; j++)
       if( mlink[i].ss[j] == '1')
       {
         i1=num+j; 
         for (j1=0 ; j1<DIM ; j1++)
            {
	          RGLOBAL[i1][j1]=0.0;
	          RGLOBAL[j1][i1]=0.0;
            }  
			RGLOBAL[i1][i1]=1.0;
	   } 
  } 
 /*---------------------------------------------*/
 /*       РЕШЕНИЕ СИCТЕМЫ УРАВНЕНИЙ             */
 /*---------------------------------------------*/

  st_solve_gauss (DIM , RGLOBAL , V_PCH , V_Z );

 it=0;

}

/**************************************************/
/*              re_st_2_2                         */
/*              =========                         */
/*    Матрица жесткости шарнирного стержня        */
/**************************************************/
void re_st_2_2 ( TPL    tpl_i ,
				 COOR   mcoor[] ,
				 FIZGEO mfizgeo[] , 
				 double cg[DIM_RE][DIM_RE]
			   )
{
  
  int n1,n2;
  double l,cosA,sinA,E,F,x1,y1,x2,y2,x21,y21;

  n1=tpl_i.num[0]-1;
  n2=tpl_i.num[1]-1;

  x1=mcoor[n1].x; y1=mcoor[n1].y;
  x2=mcoor[n2].x; y2=mcoor[n2].y;

  x21=x2-x1;
  y21=y2-y1;

  l=sqrt(x21*x21+y21*y21);

  sinA=y21/l;
  cosA=x21/l;

  E=mfizgeo[tpl_i.num_fizgeo-1].fgeo[0];
  F=mfizgeo[tpl_i.num_fizgeo-1].fgeo[1];

  cg[0][0] = cosA * cosA / l * E * F;
  cg[0][1] = cosA / l * E * F * sinA;
  cg[0][2] = -cosA * cosA / l * E * F;
  cg[0][3] = -cosA / l * E * F * sinA;
  cg[1][0] = cosA / l * E * F * sinA;
  cg[1][1] = sinA * sinA / l * E * F;
  cg[1][2] = -cosA / l * E * F * sinA;
  cg[1][3] = -sinA * sinA / l * E * F;
  cg[2][0] = -cosA * cosA / l * E * F;
  cg[2][1] = -cosA / l * E * F * sinA;
  cg[2][2] = cosA * cosA / l * E * F;
  cg[2][3] = cosA / l * E * F * sinA;
  cg[3][0] = -cosA / l * E * F * sinA;
  cg[3][1] = -sinA * sinA / l * E * F;
  cg[3][2] = cosA / l * E * F * sinA;
  cg[3][3] = sinA * sinA / l * E * F;
}
#include<calculate.h>
#define MT 3000
inline bool cal::getdf(pic_all *p){

    if(p->type<100){
        //empty
        return false;
    }
    else if(p->type>=100){
         Arton_base *lin;
        lin=datas->data_f[0].arton[p->id];
        if(!lin->a_x&&!lin->a_y&&!lin->a_z&&!lin->v_x&&!lin->v_y&&!lin->v_z)
            return false;
        else return true;
    }
}

inline double cal::getjuli(pic_all *p,pic_all *q){
       int x1,y1,z1,x2,y2,z2;double juli;
       getxyz(p,&x1,&y1,&z1);
       getxyz(q,&x2,&y2,&z2);
        juli=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1);
        return juli;
}

inline void cal::getxy(pic_all *p,int *x,int *y){
    if(p->type<100){
            //empty
           *x=*y=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *x=lin->x;*y=lin->y;
    }
}
inline void cal::getxyz(pic_all *p,int *x,int *y,int *z){
    if(p->type<100){
            //empty
           *x=*y=*z=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *x=lin->x;*y=lin->y;*z=lin->z;
    }
}

void cal::m_search1(){
    at_count=0;pic_all lin;
    for(int k=0;k<=180;k++){
        for(int i=0;i<15;i++){
            for(int j=0;j<datas->data_f[0].map_count[k][i];j++){
                         lin=datas->data_f[0].map[k][i][j];
                         if(getdf(&lin)==true)
                         {
                             active_list[at_count++]=lin;
                         }
            }
        }
    }
}
 void cal::m_search2(){
     for(int i=0;i<at_count;i++){
         pre[i]=-1;
     }
     double juli;
     fn_count=0;
     for(int i=0;i<at_count;i++){
         if(pre[i]==-1){
             pre[i]=fn_count++;
         for(int j=i+1;j<at_count;j++){
             if(pre[j]==-1){
             juli=getjuli(&active_list[i],&active_list[i]);
             if(juli<=MT)pre[j]=pre[i];
            }
         }
         }
     }
     for(int i=0;i<fn_count;i++){
         fn_list[i].x_max=-1;
         fn_list[i].x_min=99999;
         fn_list[i].y_max=-1;
         fn_list[i].y_min=99999;

     }
     int x,y;
     for(int i=0;i<at_count;i++){
       getxy(&active_list[i],&x,&y);
       if(x>fn_list[pre[i]].x_max)fn_list[pre[i]].x_max=x;
       if(x<fn_list[pre[i]].x_min)fn_list[pre[i]].x_min=x;
       if(y>fn_list[pre[i]].y_max)fn_list[pre[i]].y_max=y;
       if(y<fn_list[pre[i]].y_min)fn_list[pre[i]].y_min=y;
     }
 }

void cal::shouli(){
    if(datas->hero.y>0)datas->hero.ay=-2;
    if(datas->hero.y<0){
        datas->hero.ay=0;
        datas->hero.vy=0;
        datas->hero.y=0;
    }
}

void cal::sudujs(){
    datas->hero.vy+=datas->hero.ay;
}

void cal::weizhijs(){
    if(datas->hero.y+datas->hero.vy<0){
        datas->hero.y=0;
    }
    else datas->hero.y+=datas->hero.vy;
}
#include<database.h>
data_in::data_in(){
    for(int i=0;i<200;i++){
        for(int j=0;j<18;j++){
            map_count[i][j]=0;
        }
    }
}

Database::Database():hero(Hero()){
    hear=0;
    data_f[hear].people[0]=&hero;
    data_f[hear].people_use=true;
    data_f[hear].map[hero.x/DIS][hero.y/DIS][0].type=-1;
    data_f[hear].map[hero.x/DIS][hero.y/DIS][0].id=0;
    data_f[hear].map_count[hero.x/DIS][hero.y/DIS]++;
    //data_f=new data_in;
}
void swap(pic_all& a,pic_all& b){
    pic_all c;
    c=a;
    a=b;
    b=c;
}

void Database::new_project(int type,int x,int y,int z){
    int id,x,y;
    Life* lin;
    switch (type){
        case(0)://怪物_0
            for(int i=0;i<PEOPLE_ALL;i++){
                if(!data_f[hear].people_use[i]){
                    id=i;
                }
            }
            data_f[hear].people_use[i]=true;
            lin=data_f[hear].people=new Monster_0();
            x=lin->x/DIS;
            y=lin->y/DIS;
            data_f[hear].map[x][y][data_f[hear].map_count[x][y]++];
            break;
    }
}
void Database::new_background(int hear,int x,int y,int w,int h,int pic_id){
    for(int i=0;i<BACKGROUND_ALL;i++){
        if(data_f[hear].background_use[i]=false){
            data_f[hear].background[i]=new M_map(x,y,w,h,pic_id)
        }
    }
}

void Database::del_project(const pic_all& obj){
    int x,y;
    switch (obj.type){
        case (-1)://英雄
        case (0)://怪物
            data_f[hear].people_use[obj.id]=false;
            x=data_f[hear].people[obj]->x/DIS;
            y=data_f[hear].people[obj]->y/DIS;
            for(int i=0;i<data_f[hear].map_count[x][y];i++){
                if(data_f[hear].map[x][y][i]==obj){
                    swap(data_f[hear].map[x][y][i],data_f[hear].map[x][y][ --data_f[hear].map_count[x][y] ]);
                    break;
                }
            }
            break;

    }
}
void Database::move_project(const pic_all& obj,int x_old,int y_old){
    int x,y;
    x_old/=DIS;
    y_old/=DIS;
    switch(obj.type){
        case (-1)://英雄
        case (0)://怪物
            x=data_f[hear].people[obj.id]->x/DIS;
            y=data_f[hear].people[obj.id]->y/DIS;
            for(int i=0;i<data_f[hear].map_count[x][y];i++){
                if(data_f[hear].map[x_old][y_old][i]==obj){
                    swap(data_f[hear].map[x_old][y_old][i],data_f[hear].map[x_old][y_old][ --data_f[hear].map_count[x_old][y_old] ]);
                    break;
                }
            }
            swap(data_f[hear].map[x_old][y_old][ data_f[hear].map_count[x_old][y_old] ],data_f[hear].map[x][y][ data_f[hear].map_count[x][y]++ ]);
            break;
    }

}

void move_project(int type,int id,int x_old,int y_old){
    pic_all lin;
    lin.type=type;
    lin.id=id;
    this->move_project(lin,x_old,y_old);
}

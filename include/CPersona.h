#ifndef CPERSONA_H
#define CPERSONA_H


class CPersona
{
private:
    int vida;
	int nivel;
	int atk;
	int dfs;
	int xpmax;
	int xp;
	int x;
	int y;
    public:
       CPersona();
        virtual ~CPersona();

        void setvida(int h);
        void setatk(int s);
        void setnivel(int m);
        void setdfs (int d);
        void setxp (int x);
        void setxpmax (int xp);
        void setx (int x);
        void sety (int y);

      int get_atk();
      int get_vida();
      int get_dfs();
      int get_nivel();
      int get_xp();
      int get_xpmax();
      int get_x();
      int get_y();
      int aumento_nivel();
};

#endif // CPERSONA_H

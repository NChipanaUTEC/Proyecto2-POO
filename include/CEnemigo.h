#ifndef CENEMIGO_H
#define CENEMIGO_H


class CEnemigo
{
private:
    int vidae;
	int atke;
	int dfse;
public:
    CEnemigo();
    virtual ~CEnemigo();
    void setvidae(int h);
    void setatke(int h);
    void setdfse(int h);

    int get_atke();
    int get_vidae();
    int get_dfse();
};

#endif // CENEMIGO_H

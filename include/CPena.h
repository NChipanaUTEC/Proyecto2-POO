#ifndef CPENA_H
#define CPENA_H

class CPena
{
private:
    int vidae;
	int atke;
	int dfse;
public:
    CPena();
    virtual ~CPena();
    void setvidae(int h);
    void setatke(int h);
    void setdfse(int h);

    int get_atke();
    int get_vidae();
    int get_dfse();
};

#endif // CENEMIGO_H

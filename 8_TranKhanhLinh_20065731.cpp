#include<iostream>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#define RH 1 // cây con phải cao hơn
#define EH 0 // 2 cây bằng nhau
#define LH -1 // câu con trái cao hơn
using namespace std;
struct NGAYTHANG{
    int ngay;
    int thang;
    int nam;
};
struct CHUYENBAY
{
    char MaChuyen[5];
    char HoTenPC[30];
    NGAYTHANG NgayBay;
    int SucChua;
};
struct node
{
    char balFactor; // chỉ số cân bằng
    CHUYENBAY data;
    node * left;
    node * right;
};
typedef struct node* AVLTree;
// Nhập chuyến bay
void menu();
void NhapChuyenBay(CHUYENBAY &x);
void init(AVLTree &t);
// tạo node
node * Getnode(CHUYENBAY x);
// cây con trái lệch trái
void Rotate_Left_Left(AVLTree &t);
//cây con phải lệch phải
void Rotate_Right_Right(AVLTree &t);
//cây con phải lệch trái
void Rotate_Right_Left(AVLTree &t);
//cay con trái lệch phải
void Rotate_Left_Right(AVLTree &t);
//Can bang cay lech trai
int BalanceLeft(AVLTree &t);
//can bang cay lech phai
int BalanceRight(AVLTree &t);
// chèn chuyến bay
int ThemChuyenBay(AVLTree &t, CHUYENBAY x);
void TaoDSChuyenBay(AVLTree &t);
node* TimChuyenBay(AVLTree t, char a[]);
int CapNhatChuyenBay(AVLTree &t, char a[]);
//Tim node the mang
int SearchStandFor(AVLTree &t, node *&p);
//Xoa 1 node tren cay
int DelNode(AVLTree &t, char a[]);
void Xuat1ChuyenBay(CHUYENBAY x);
void XuatDanhSach(AVLTree t);
void tieuDe();
void ghi_1lan(CHUYENBAY x, char filename[]);
void ghi_file(AVLTree t, char filename[]);
void doc_file(AVLTree &t, char filename[]);
void SucChuaMax(AVLTree t, int &max);
void ListChuyenBaySucChuaMax(AVLTree t,int max);
void TongSoChuyenBay(AVLTree t, int &dem , int ngay, int thang, int nam);
void DemSoLanBay(AVLTree t, char tenpc[], int &dem, int nam);
int main()
{
    AVLTree t;
    init(t);
    int chon;
    int chon1;
    do
    {
        menu();
        scanf("%d",&chon);
        switch(chon)
        {
            case 1:
                {
                  TaoDSChuyenBay(t);
                  do
                  {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                  }while(!(chon1==1||chon1 == 0));
                  if(chon1==0)
                  {
                      chon = 0;
                  }else
                  {
                      system("cls");
                  }
                }
                break;
            case 2:
                {
                  char filename[] = "danhsach1.txt";
                  doc_file(t,filename);
                  printf("doc thanh cong\n");
                  do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 3:
                {
                    char filename[] = "DanhSach2.txt";
                    FILE * p = fopen(filename,"w");
                    remove(filename);
                    fclose(p);
                    ghi_file(t,filename);
                    printf("ghi thanh cong\n");
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 4:
                {
                    char a[5];
                    printf("nhap ma chuyen bay muon xoa: ");
                    fflush(stdin);
                    scanf("%s",a);
                    int kt = DelNode(t,a);
                    if(kt == 0)
                    {
                        printf("khong tim thay chuyen bay muon xoa\n");
                    }else
                    {
                        printf("xoa thanh cong\n");
                    }
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 5:
                {
                    char a[5];
                    printf("nhap ma chuyen bay muon tim: ");
                    fflush(stdin);
                    scanf("%s",a);
                    node * p = TimChuyenBay(t,a);
                    if(p==NULL)
                    {
                        printf("khong tim thay chuyen bay muon tim\n");
                    }else
                    {
                        tieuDe();
                        Xuat1ChuyenBay(p->data);
                    }
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 6:
                {
                    char a[5];
                    printf("nhap ma chuyen bay muon cap nhat: ");
                    fflush(stdin);
                    scanf("%s",a);
                    int kt = CapNhatChuyenBay(t,a);
                    if(kt == 0)
                    {
                        printf("khong tim thay chuyen bay muon cap nhat\n");
                    }else
                    {
                        printf("cap nhat thanh cong\n");
                    }
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 7:
                {
                    printf("Danh sach chuyen bay co suc chua lon nhat\n");
                    tieuDe();
                    int maxx;
                    SucChuaMax(t,maxx);
                    ListChuyenBaySucChuaMax(t,maxx);
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 8:
                {
                    printf("tinh tong so chuyen bay trong 1 ngay\n");
                    printf("nhap ngay/thang/nam: ");
                    int ngay, thang, nam;
                    do
                    {
                        printf("nhap ngay bay muon tinh(dd/mm/yyyy):");
                        scanf("%d/%d/%d",&ngay,&thang,&nam);
                    } while (!(ngay>0&&ngay<=31&&thang>0&&thang<=12&&nam>=2020&&nam<=2025));
                    int dem = 0;
                    TongSoChuyenBay(t, dem, ngay, thang, nam);
                    if(dem == 0)
                    {
                        printf("khong co chuyen bay nao vao ngay %d / %d / %d\n", ngay, thang, nam);
                    }else
                    {
                        printf("Co %d chuyen bay nao vao ngay %d / %d / %d\n",dem, ngay, thang, nam);
                    }
                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 9:
                {
                    printf("Dem so lan bay cua phi cong vao nam bat ki\n");
                    printf("nhap nam: ");
                    int nam;
                    do
                    {
                        printf("nhap nam bay muon dem :");
                        scanf("%d",&nam);
                    } while (!(nam>=2020&&nam<=2025));
                    char a[20];
                    fflush(stdin);
                    printf("nhap ten phi cong: ");
                    gets(a);
                    int dem = 0;
                    DemSoLanBay(t, a, dem, nam);
                    if(dem == 0)
                    {
                        printf("Khong co chuyen bay nao vao nam  %d\n", nam);
                    }else
                    {
                        printf("Co %d chuyen bay nao vao nam %d \n",dem, nam);
                    }

                    do
                    {
                      printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                      scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                      chon = 0;
                    }else
                    {
                      system("cls");
                    }
                }
                break;
            case 10:
                {
                    printf("Danh sach chuyen bay\n");
                    tieuDe();
                    XuatDanhSach(t);
                    do
                    {
                        printf("ban co muon chon tiep?(0: Khong / 1: Co)\n");
                        scanf("%d",&chon1);
                    }while(!(chon1==1||chon1 == 0));
                    if(chon1==0)
                    {
                        chon = 0;
                    }else
                    {
                        system("cls");
                    }
                }
                break;
            default:
                break;
        }
    }while(chon!=0);
    return 0;
}
void menu()
{
    printf("______MENU______\n");
    printf("1.Them chuyen bay\n");
    printf("2.Doc file chuyen bay\n");
    printf("3.Ghi file chuyen bay\n");
    printf("4.Xoa chuyen bay theo ma\n");
    printf("5.Tim chuyen bay theo ma\n");
    printf("6.Cap nhat chuyen bay theo ma\n");
    printf("7.Liet ke chuyen bay co suc chua lon nhat\n");
    printf("8.Tinh tong so chuyen bay trong 1 ngay\n");
    printf("9.Dem so lan bay cua phi cong vao thang bat ki\n");
    printf("10.Xuat danh sach\n");
    printf("0.Thoat\n");
    printf("Moi chon: ");
}
void NhapChuyenBay(CHUYENBAY &x)
{
    fflush(stdin);
    printf("nhap ma chuyen bay:");
    scanf("%s",x.MaChuyen);
    fflush(stdin);
    printf("nhap ho ten phi cong:");
    gets(x.HoTenPC);
    fflush(stdin);
    do
    {
        printf("nhap ngay bay(dd/mm/yyyy):");
        scanf("%d/%d/%d",&x.NgayBay.ngay,&x.NgayBay.thang,&x.NgayBay.nam);
    } while (!(x.NgayBay.ngay>0&&x.NgayBay.ngay<=31&&x.NgayBay.thang>0&&x.NgayBay.thang<=12&&x.NgayBay.nam>=2020));
    do
    {
        printf("nhap suc chua:");
        scanf("%d",&x.SucChua);
    } while (x.SucChua<=0);
}
void init(AVLTree &t)
{
    t=NULL;
}
node * Getnode(CHUYENBAY x)
{
    node * p =new node();
    if(p==NULL)
    {
        printf("khong the cap nhat bo nho\n");
        return NULL;
    }
    p->balFactor = EH;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void Rotate_Left_Left(AVLTree &t)
{
    node *p= t->left;
    t->left = p->right;
    p->right = t;

    switch (p->balFactor)
    {
    case LH:
        t->balFactor = EH;
        t->balFactor = EH;
        break;
    case EH:
        p->balFactor = RH;
        t->balFactor = LH;
        break;
    }

    t = p;
}
void Rotate_Right_Right(AVLTree &t)
{
    node *p = t->right;
    t->right = p->left;
    p->left = t;

    switch (p->balFactor)
    {
    case EH:
        t->balFactor = RH;
        p->balFactor = EH;
        break;
    case RH:
        p->balFactor = EH;
        t->balFactor = EH;
        break;
    }

    t = p;
}
void Rotate_Right_Left(AVLTree &t)
{
    node *p1, *p2;

    p1 = t->right;
    p2 = p1->left;
    t->right = p2->left;
    p1->left = p2->right;
    p2->left = t;
    p2->right = p1;

    switch (p2->balFactor)
    {
    case LH:
        t->balFactor = EH;
        p1->balFactor = RH;
        break;
    case EH:
        t->balFactor = EH;
        p1->balFactor = EH;
        break;
    case RH:
        t->balFactor = LH;
        p1->balFactor = EH;
        break;
    }

    p2->balFactor = EH;
    t = p2;
}

void Rotate_Left_Right(AVLTree &t)
{
    node *p1, *p2;
    p1 = t->left;
    p2 = p1->right;
    t->left = p2->right;
    p1->right = p2->left;
    p2->right = t;
    p2->left = p1;

    switch (p2->balFactor)
    {
    case LH:
        p1->balFactor = EH;
        t->balFactor = RH;
        break;
    case EH:
        t->balFactor = EH;
        p1->balFactor = EH;
        break;
    case RH:
        t->balFactor = EH;
        p1->balFactor = LH;
        break;
    }

    p2->balFactor = EH;
    t = p2;
}
int BalanceLeft(AVLTree &t)
{
    node *p= t->left;
    switch (p->balFactor)
    {
    case LH:
        Rotate_Left_Left(t);
        return 2;
    case EH:
        Rotate_Left_Left(t);
        return 1;
    case RH:
        Rotate_Left_Right(t);
        return 2;
    }
}
int BalanceRight(AVLTree &t)
{
    node *p = t->right;
    switch (p->balFactor)
    {
    case RH:
        Rotate_Right_Right(t);
        return 2;
    case EH:
        Rotate_Right_Right(t);
        return 1;
    case LH:
        Rotate_Right_Left(t);
        return 2;
    }
}
int ThemChuyenBay(AVLTree &t, CHUYENBAY x)
{
    int res;
    if(t==NULL)
    {
        t=Getnode(x);
        return 2;
    }
    else
    {
        if(stricmp(x.MaChuyen,t->data.MaChuyen)==0)
            return 0; // tồn tại mã chuyến
        // chèn trái
        if(stricmp(x.MaChuyen,t->data.MaChuyen)<0)
        {
            res = ThemChuyenBay(t->left,x);
            if(res <2)
                return res;
            switch (t->balFactor)
            {
                case RH:t->balFactor = EH;return 1;

                case EH:t->balFactor = LH;return 2;

                case LH:BalanceLeft(t);return 1;

            }
        }else
        {
            // chèn phải
            res = ThemChuyenBay(t->right,x);
            if(res < 2)
                return res;
            switch (t->balFactor)
            {
            case LH:t->balFactor = EH;return 1;
                break;
            case EH:t->balFactor = RH;return 2;
                break;
            case RH:BalanceRight(t);return 1;
                break;
            default:
                break;
            }
        }
    }
}
void TaoDSChuyenBay(AVLTree &t)
{
    CHUYENBAY x;
    int chon;
    do
    {
        printf("Co muon nhap thong tin chuyen bay khong? (1:Co  /  0: Khong): ");
        scanf("%d",&chon);
        if(chon==0)
            return;
        NhapChuyenBay(x);
        int kt = ThemChuyenBay(t,x);
        if(kt == 0)
        {
            printf("them that bai\n");
        }else
        {
            char filename[] = "DanhSach2.txt";
            ghi_1lan(x,filename);
        }
    } while (true);
}
node* TimChuyenBay(AVLTree t, char a[])
{
    if(t==NULL)
        return NULL;
    else
    {
        if(stricmp(t->data.MaChuyen,a)==0)
            return t;
        if(stricmp(t->data.MaChuyen,a)>0)
            return TimChuyenBay(t->left,a);
        else
            return TimChuyenBay(t->right,a);
    }
}
int CapNhatChuyenBay(AVLTree &t, char a[])
{
    node *p = TimChuyenBay(t,a);
    if(p==NULL)
        return 0;
    fflush(stdin);
    printf("nhap ho ten phi cong:");
    gets(t->data.HoTenPC);
    fflush(stdin);
    do
    {
        printf("nhap ngay bay(dd/mm/yyyy):");
        scanf("%d/%d/%d",&t->data.NgayBay.ngay,&t->data.NgayBay.thang,&t->data.NgayBay.nam);
    } while (!(t->data.NgayBay.ngay>=0&&t->data.NgayBay.ngay<=31&&t->data.NgayBay.thang>=0&&t->data.NgayBay.thang<=12&&t->data.NgayBay.nam>=2020));
    do
    {
        printf("nhap suc chua:");
        scanf("%d",&t->data.SucChua);
    } while (t->data.SucChua<=0);
    return 1;
}
int SearchStandFor(AVLTree &t, node *&p)
{
    int res;

    if (p->left)
    {
        res = SearchStandFor(t, p->left);

        if (res < 2) return res;

        switch (p->balFactor)
        {
        case LH:
            p->balFactor = EH;
            return 1;
        case EH:
            p->balFactor = RH;
            return 2;
        case RH:
            return BalanceRight(t);
        }
    }

    t->data = p->data;
    t = p;
    p = p->right;
    return 2;
}

int DelNode(AVLTree &t, char a[])
{
    int Res;

    //Khong ton tai node nay tren cay
    if (t==NULL)
        return 0;

    if (stricmp(t->data.MaChuyen,a)>0)
    {
        Res = DelNode(t->left, a);

        //Neu co xoa thi Res = 1 hoac 2. 2 tuc thay doi chieu cao cay
        if (Res < 2) return Res;

        //Chieu cao bi thay doi
        switch (t->balFactor)
        {
        case LH:
            t->balFactor = EH;
            return 2;
        case EH:
            t->balFactor = RH;
            return 1;
        case RH:
            return BalanceRight(t);
        }
    }

    if (stricmp(t->data.MaChuyen,a)< 0)
    {
        Res = DelNode(t->right, a);

        if (Res < 2) return Res;

        switch (t->balFactor)
        {
        case LH:
            return BalanceLeft(t);
        case EH:
            t->balFactor = LH;
            return 1;
        case RH:
            t->balFactor = EH;
            return 2;
        }
    }
    else
    {
        //t->x = x
        node *p1 = t;

        if (t->left == NULL)
        {
            t = t->right;
            Res = 2;
        }
        else
        {
            if (t->right == NULL)
            {
                t = t->left;
                Res = 2;
            }
            else
            {
                Res = SearchStandFor(p1, t->right);

                if (Res < 2) return Res;
                switch (t->balFactor)
                {
                case RH:
                    t->balFactor = EH;
                    return 2;
                case EH:
                    t->balFactor = LH;
                    return 1;
                case LH:
                    return BalanceRight(t);
                }
            }
            delete p1;
            return Res;
        }
    }

}

void Xuat1ChuyenBay(CHUYENBAY x)
{
    printf("%-20s%-30s%d/%d/%-10d%-10d\n",x.MaChuyen,x.HoTenPC,x.NgayBay.ngay,x.NgayBay.thang,x.NgayBay.nam,x.SucChua);
}
void XuatDanhSach(AVLTree t)
{
    if(t!=NULL)
    {
        XuatDanhSach(t->left);
        Xuat1ChuyenBay(t->data);
        XuatDanhSach(t->right);
    }
}
void tieuDe()
{
    printf("%-20s%-30s%-14s%-10s\n","Ma Chuyen","Ho ten phi cong","ngay bay","suc chua");
}
void ghi_1lan(CHUYENBAY x, char filename[])
{
    FILE * p = fopen(filename,"a");
      fprintf(p,"%s",x.MaChuyen);
      fprintf(p,"%s"," ");
      fprintf(p,"%d",x.NgayBay.ngay);
      fprintf(p,"%s"," ");
      fprintf(p,"%d",x.NgayBay.thang);
      fprintf(p,"%s"," ");
      fprintf(p,"%d",x.NgayBay.nam);
      fprintf(p,"%s"," ");
      fprintf(p,"%d",x.SucChua);
      fprintf(p,"%s"," ");
      fputs(x.HoTenPC,p);
      fprintf(p,"%s","\n");
    fclose(p);
}
void ghi_file(AVLTree t, char filename[])
{
    if(t!=NULL)
    {
        ghi_file(t->left,filename);
            ghi_1lan(t->data,filename);
        ghi_file(t->right,filename);
    }
}
void doc_file(AVLTree &t, char filename[])
{
    FILE * p = fopen(filename,"r");
    rewind(p);
    while (!feof(p))
    {
      CHUYENBAY x;
      fscanf(p,"%s",x.MaChuyen);
      fscanf(p,"%d",&x.NgayBay.ngay);
      fscanf(p,"%d",&x.NgayBay.thang);
      fscanf(p,"%d",&x.NgayBay.nam);
      fscanf(p,"%d",&x.SucChua);
      fgets(x.HoTenPC,sizeof(x.HoTenPC),p);
      int n = strlen(x.HoTenPC);
      x.HoTenPC[n-1]= '\0';
      for (int i = 0; i < strlen(x.HoTenPC); i++)
      {
          x.HoTenPC[i]= x.HoTenPC[i+1];
      }
      ThemChuyenBay(t,x);
    }
    fclose(p);
}
void SucChuaMax(AVLTree t, int &max)
{
    if(t!=NULL)
    {
        SucChuaMax(t->left,max);
        if(t->data.SucChua > max)
                max = t->data.SucChua;
        SucChuaMax(t->right,max);
    }

}
void ListChuyenBaySucChuaMax(AVLTree t,int max)
{
    if(t!=NULL)
    {
        ListChuyenBaySucChuaMax(t->left,max);
        if(t->data.SucChua == max)
            Xuat1ChuyenBay(t->data);
        ListChuyenBaySucChuaMax(t->right,max);
    }
}
void TongSoChuyenBay(AVLTree t, int &dem , int ngay, int thang, int nam)
{
    if(t!=NULL)
    {
        TongSoChuyenBay(t->left, dem, ngay, thang, nam);
        if(t->data.NgayBay.ngay == ngay &&t->data.NgayBay.thang == thang &&t->data.NgayBay.nam == nam)
                dem++;
        TongSoChuyenBay(t->right, dem, ngay, thang, nam);
    }
}
void DemSoLanBay(AVLTree t, char tenpc[], int &dem, int nam)
{
    if(t!=NULL)
    {
        DemSoLanBay(t->left,tenpc,dem, nam);
        if(stricmp(t->data.HoTenPC,tenpc)==0&& t->data.NgayBay.nam == nam )
            dem++;
        DemSoLanBay(t->right,tenpc,dem, nam);
    }
}





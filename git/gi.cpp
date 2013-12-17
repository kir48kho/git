// Слияние двух упорядоченных массивов
    // m1 - Первый массив
    // m2 - Второй массив
    // l1 - Длина первого массива
    // l2 - Длина второго массива
    // Возвращает объединённый массив

    //template <class T>
    int* merge(int *m1, int* m2, int l1, int l2){
        int* ret = new int[l1+l2];
        int n = 0;
        // Сливаем массивы, пока один не закончится
        while (l1 && l2){
            if (*m1 < *m2){
               ret[n] = *m1;
               m1++; l1--;}
            else {
               ret[n] = *m2;
               m2++; l2--;}
           n++;}
        // Если закончился первый массив
        if (l1 == 0){
            for (int i=0; i<l2; i++){
                ret[n++] = *m2++;}}
        // Если закончился второй массив
        else {
            for (int i=0; i<l1; i++){
               ret[n++] = *m1++;}}
        return ret;}

    // Функция восходящего слияния
    //template <class T>
    void mergeSort(int * mas, int len){
        int n=1, l, ost;
        int * mas1;
        while (n<len){
            l=0;
            while (l<len){
               if (l+n >= len) break;
               ost = (l+n*2>len) ? (len-(l+n)) : n;
               mas1 = merge(mas+l, mas+l+n, n, ost);
               for (int i=0; i<n+ost; i++) mas[l+i] = mas1[i];
               delete [] mas1;
               l+=n*2;}
           n*=2;
    }}

    void sort(int A[], int n){

    int i,i1,i2,s,k;

    for (s=1; 1; s*=2){               // Размер группы кратен степени 2

        int nn=n/s;                   // Количество групп по s элементов

        if (n%s!=0) nn++;             // Остаток – есть неполная группа

        int n1=nn/2*s;                // Деление ближе к середине,

        int n2=n-n1;                  // но кратно размеру группы

        if (n1<=0 || n2<=0) return;       // Часть больше целого - выход

        int *B1=new int[n1],*B2=new int[n2];

        for (i=0; i<n1; i++) B1[i]=A[i];   // Разделение на части

        for (i=0; i<n2; i++) B2[i]=A[i+n1];

        i1=i2=0;

        for (i=0,k=0; i<n; i++){           // Слияние с переходом «скачком»

            if (i1==s && i2==s)            // при достижении границ обеих

                k+=s,i1=0,i2=0;            // групп

            if (i1==s || k+i1==n1) A[i]=B2[k+i2++];  // Достигла границы группы или

            else                           // массива

                if (i2==s || k+i2==n2) A[i]=B1[k+i1++];

                else                       // Если нет – минимальный из пары

                    if (B1[k+i1 ] < B2[k+i2 ]) A[i]=B1[k+i1++];

                    else A[i]=B2[k+i2++];

        }

        delete []B1; delete []B2;

    }}

void sort(int A[], int n){

    int i,i1,i2,s,k;

    for (s=1; 1; s*=2){               // Размер группы кратен степени 2

        int nn=n/s;                   // Количество групп по s элементов

        if (n%s!=0) nn++;             // Остаток – есть неполная группа

        int n1=nn/2*s;                // Деление ближе к середине,

        int n2=n-n1;                  // но кратно размеру группы

        if (n1<=0 || n2<=0) return;       // Часть больше целого - выход

        int *B1=new int[n1],*B2=new int[n2];

        for (i=0; i<n1; i++) B1[i]=A[i];   // Разделение на части

        for (i=0; i<n2; i++) B2[i]=A[i+n1];

        i1=i2=0;

        for (i=0,k=0; i<n; i++){           // Слияние с переходом «скачком»

            if (i1==s && i2==s)            // при достижении границ обеих

                k+=s,i1=0,i2=0;            // групп

            if (i1==s || k+i1==n1) A[i]=B2[k+i2++];  // Достигла границы группы или

            else                           // массива

                if (i2==s || k+i2==n2) A[i]=B1[k+i1++];

                else                       // Если нет – минимальный из пары

                    if (B1[k+i1 ] < B2[k+i2 ]) A[i]=B1[k+i1++];

                    else A[i]=B2[k+i2++];

        }

        delete []B1; delete []B2;

    }}
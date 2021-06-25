#include <iostream>
class Onur_DLL
{
	int data = NULL;
	Onur_DLL* oteki;
	Onur_DLL* beriki;
public:
	Onur_DLL(int data) {
		this->data = data;
		oteki = NULL;
		beriki = NULL;
	}
	Onur_DLL* sonaadd(Onur_DLL* dip, Onur_DLL* next)
	{
		if (dip == NULL) {
			return next;
		}
		Onur_DLL* temp = dip;
		while (temp->oteki != NULL)
		{
			temp = temp->oteki;
		}
		next->beriki = temp;
		temp->oteki = next;
		next->oteki = NULL;
		return dip;
	}
	Onur_DLL* basaadd(Onur_DLL* dip, Onur_DLL* prev)
	{
		if (dip == NULL) {
			return prev;
		}
		while (dip->beriki != NULL)
		{
			dip = dip->beriki;
		}
		dip->beriki = prev;
		prev->oteki = dip;
		while (dip->beriki != NULL)
		{
			dip = dip->beriki;
		}

		dip->beriki = NULL;
		return dip;
	}
	Onur_DLL* arayaadd(Onur_DLL* dip, Onur_DLL* mid, int data)
	{
		if (dip == NULL) {
			return mid;
		}
		Onur_DLL* temp = dip;
		while (temp->data != data)
		{
			temp = temp->oteki;
		}
		if (temp->oteki == NULL)
		{
			sonaadd(dip, mid);
			return dip;
		}
		mid->beriki = temp;
		temp->oteki->beriki = mid;
		mid->oteki = temp->oteki;
		temp->oteki = mid;

		return dip;
	}
	Onur_DLL* sondanremove(Onur_DLL* dip)
	{
		if (dip == NULL)
			return dip;


		Onur_DLL* temp = dip;
		while (temp->oteki != NULL)
		{
			temp = temp->oteki;
		}
		if (temp->beriki == NULL)
		{
			std::cout << "Silme işlemi başarılı, listede düğüm kalmadı.\n";
			free(temp);
			return 0;
		}
		temp->beriki->oteki = NULL;
		temp->beriki = NULL;
		free(temp);
		return dip;
	}
	Onur_DLL* bastanremove(Onur_DLL* dip)
	{
		if (dip == NULL)
			return dip;
		if (dip->oteki == NULL)
		{
			std::cout << "Son elemanı da sildiniz. İşlem başarılı.\n";
			free(dip);
			return 0;
		}

		dip->oteki->beriki = NULL;
		dip = dip->oteki;
		free(dip->beriki);
		return dip;

	}
	Onur_DLL* aradanremove(Onur_DLL* dip, int remove)
	{
		Onur_DLL* temp = dip;
		if (dip == NULL)
			return dip;

		while (temp->data != remove)
		{
			if (temp->oteki == NULL)
				return dip;
			temp = temp->oteki;
		}
		if (temp->beriki == NULL)
		{
			dip = bastanremove(dip);
			return dip;
		}
		if (temp->oteki == NULL)
		{
			sondanremove(dip);
			return dip;
		}
		temp->oteki->beriki = temp->beriki;
		temp->beriki->oteki = temp->oteki;
		free(temp);
		return dip;
	}
	void ciktilar(Onur_DLL* dip)
	{
		if (dip == NULL)
			std::cout << "Listede eleman yok!.\n";
		std::cout << "\n";
		while (dip != NULL)
		{

			printf("data= %d \n", int(dip->data));

			dip = dip->oteki;
		}
		std::cout << "\n";
	}
};
class Can_stack
{
	int size = 0;
	int top = 0;
	int* dizi = NULL;
public:
	Can_stack() {
		size = 1;
		dizi = (int*)malloc(sizeof(int) * 2);
	}
	void push(int data) {
		if (dizi == NULL) {
			dizi = (int*)malloc(sizeof(int) * size * 2);
		}
		if (top >= size - 1) {
			int* dizi_temp = (int*)malloc(sizeof(int) * size * 2);
			for (int i = 0; i < size; i++)
			{
				dizi_temp[i] = dizi[i];
			}
			free(dizi);
			dizi = dizi_temp;
			size *= 2;

		}
		dizi[top++] = data;
	}
	int pop() {

		if (dizi == NULL || top < 0) {
			std::cout << "Stack Boş\n";
			return -1;
		}

		if (top <= size / 4) {
			int* dizi_temp = (int*)malloc(sizeof(int) * size);
			for (int i = 0; i < top; i++)
				dizi_temp[i] = dizi[i];
			free(dizi);
			dizi = dizi_temp;
			size /= 2;

		}
		return dizi[--top];
	}

	void ciktilarir() {
		std::cout << "---------\nboyut: " << size << "\n";
		for (int i = 0; i < top; i++)
		{
			std::cout << "veri: " << dizi[i] << "\n";
		}
	}
};

class Can_circularqueue {
	int arraysize;
	int* dizi;
	int sirabasi;
	int sirasonu;
	int verisayisi;
public:
	Can_circularqueue(int data) {
		this->arraysize = data;
		sirabasi = -1;
		sirasonu = -1;
		verisayisi = 0;
		dizi = (int*)malloc(sizeof(int) * arraysize);
	}
	bool enque(int data)
	{

		if (verisayisi >= arraysize)
		{
			std::cout << "Veriler eklenemedi. Dizide boş alan yok.\n";
			return false;
		}
		if (sirabasi == -1)
			sirabasi++;
		if (sirasonu == arraysize - 1)
			sirasonu = 0;
		else
			sirasonu++;
		dizi[sirasonu] = data;
		std::cout << "Veri: " << dizi[sirasonu] << " eklendi \n";
		verisayisi++;
		return true;
	}
	bool deque()
	{
		if (verisayisi == 0)
		{
			std::cout << "Dizi boş.\n";
			return false;
		}


		if (sirabasi == arraysize - 1)
			sirabasi = 0;
		else
		{
			std::cout << "Veri:" << dizi[sirabasi] << " çıkarıldı \n";
			sirabasi++;
		}

		verisayisi--;
		if (verisayisi <= 0) {
			sirabasi = sirasonu = -1;
			std::cout << "Dizi boş.\n";
		}
		return true;
	}
	void ciktilar() {
		std::cout << "Dizinin son hali: ";
		if (sirabasi < sirasonu) {
			for (int i = sirabasi; i <= sirasonu; i++)
			{
				std::cout << dizi[i] << " ";
			} std::cout << "\n";
		}
		else if (sirabasi > sirasonu)
		{
			for (int i = sirabasi; i < arraysize; i++)
			{
				std::cout << dizi[i] << " ";
			}
			for (int i = 0; i <= sirasonu; i++)
			{
				std::cout << dizi[i] << " ";
			} std::cout << "\n";
		}
		else if (sirabasi == -1)
		{
			std::cout << "Dizide eleman bulunmamaktadır. \n";
		}
		else
		{
			for (int i = sirabasi; i <= sirasonu; i++)
			{
				std::cout << dizi[i] << " ";
			} std::cout << "\n";
		}
		std::cout << "\n";
	}
};

class Erte_QuickSort {
	int* dizi = NULL;
	int pivot, qsboyut;
public:
	Erte_QuickSort(int qsboyut)
	{
		this->qsboyut = qsboyut;
		dizi = (int*)malloc(sizeof(int) * qsboyut);

	}
	void atama() {
		int eleman;
		std::cout << "Sıralamak istediğiniz elemanları giriniz:";
		for (int i = 0; i < qsboyut; i++)
		{
			std::cin >> eleman;
			dizi[i] = eleman;

		}
	}
	void degisTokusFonk(int* degiscek1, int* degiscek2)
	{
		int temp = *degiscek1;
		*degiscek1 = *degiscek2;
		*degiscek2 = temp;
	}
	int bolenfonk(int enKucuk, int enBuyuk)
	{
		pivot = dizi[enBuyuk];
		int i = (enKucuk - 1);
		for (int j = enKucuk; j <= enBuyuk - 1; j++)
		{
			if (dizi[j] < pivot)
			{
				i++;
				degisTokusFonk(&dizi[i], &dizi[j]);
			}
		}
		degisTokusFonk(&dizi[i + 1], &dizi[enBuyuk]);
		return (i + 1);
	}
	void SıralamaIslemi(int enKucuk, int enBuyuk)
	{
		if (enKucuk < enBuyuk)
		{
			int bolumNoktasi = bolenfonk(enKucuk, enBuyuk);
			SıralamaIslemi(enKucuk, bolumNoktasi - 1);
			SıralamaIslemi(bolumNoktasi + 1, enBuyuk);
		}
	}
	void ciktilar() {
		std::cout << "Sıralanmış dizi:";
		for (int i = 0; i < qsboyut; i++)
			std::cout << dizi[i] << " ";
		std::cout << "\n";
	}
};

class Erte_InsertionSort {
	int* dizi = NULL;
	int isboyut;
public:
	Erte_InsertionSort(int isboyut)
	{
		this->isboyut = isboyut;
		dizi = (int*)malloc(sizeof(int) * isboyut);

	}
	void atama() {
		std::cout << "Elemanları giriniz: ";
		for (int i = 0; i < isboyut; i++)
		{
			int eleman;
			std::cin >> eleman;
			dizi[i] = eleman;
		}
	}
	void SiralamaIslemi()
	{
		int i, AnahtarEleman, j;
		for (i = 1; i < isboyut; i++)
		{
			AnahtarEleman = dizi[i];
			j = i - 1;
			while (j >= 0 && dizi[j] > AnahtarEleman)
			{
				dizi[j + 1] = dizi[j];
				j--;
			}
			dizi[j + 1] = AnahtarEleman;
		}
	}
	void ciktilar() {
		std::cout << "Sıralanmış dizi:\n";
		for (int i = 0; i < isboyut; i++)
			std::cout << dizi[i] << " ";
		std::cout << "\n";
	}
};

class Kin_MergeSort {
	int* dizi = NULL;
	int msboyut;
public:
	Kin_MergeSort(int msboyut)
	{
		this->msboyut = msboyut;
		dizi = (int*)malloc(sizeof(int) * msboyut);

	}
	void atama() {
		std::cout << "Elemanları giriniz: ";
		for (int i = 0; i < msboyut; i++)
		{
			int eleman;
			std::cin >> eleman;
			dizi[i] = eleman;
		}
	}
	void SiralamaIslemi(int sol, int sag)
	{
		if (sol < sag)
		{
			int orta = sol + (sag - sol) / 2;

			SiralamaIslemi(sol, orta);
			SiralamaIslemi(orta + 1, sag);
			BirlestirmeIslemi(sol, orta, sag);
		}
	}
	void BirlestirmeIslemi(int sol, int orta, int sag)
	{
		int i, j, k;
		int solDizi = orta - sol + 1;
		int sagDizi = sag - orta;

		int* Temp_SolDizi = (int*)malloc(sizeof(int) * solDizi);
		int* Temp_SagDizi = (int*)malloc(sizeof(int) * sagDizi);

		for (i = 0; i < solDizi; i++)
			Temp_SolDizi[i] = dizi[sol + i];
		for (j = 0; j < sagDizi; j++)
			Temp_SagDizi[j] = dizi[orta + 1 + j];

		i = 0;
		j = 0;
		k = sol;

		while (i < solDizi && j < sagDizi)
		{
			if (Temp_SolDizi[i] <= Temp_SagDizi[j])
			{
				dizi[k] = Temp_SolDizi[i];
				i++;
			}
			else
			{
				dizi[k] = Temp_SagDizi[j];
				j++;
			}
			k++;
		}
		while (i < solDizi)
		{
			dizi[k] = Temp_SolDizi[i];
			i++;
			k++;
		}
		while (j < sagDizi)
		{
			dizi[k] = Temp_SagDizi[j];
			j++;
			k++;
		}
	}
	void ciktilar() {
		std::cout << "Sıralanmış dizi: \n";
		for (int i = 0; i < msboyut; i++)
			std::cout << dizi[i] << " ";
		std::cout << "\n";
	}
};

class Kin_CountingSort {
	int* dizi = NULL;
	int csboyut;
public:
	Kin_CountingSort(int csboyut)
	{
		this->csboyut = csboyut;
		dizi = (int*)malloc(sizeof(int) * csboyut);

	}
	void atama() {
		std::cout << "Elemanları giriniz: ";
		for (int i = 0; i < csboyut; i++)
		{
			int eleman;
			std::cin >> eleman;
			dizi[i] = eleman;
		}
	}
	void SiralamaIslemi() {
		int i, j, tempcssize;
		int son = 0;
		int min, max;

		min = max = dizi[0];

		for (i = 1; i < csboyut; i++) {
			min = (dizi[i] < min) ? dizi[i] : min;
			max = (dizi[i] > max) ? dizi[i] : max;
		}

		tempcssize = max - min + 1;

		int* temp_dizi = (int*)malloc(sizeof(int) * tempcssize);
		for (i = 0; i < tempcssize; i++)
		{
			temp_dizi[i] = 0;
		}

		for (i = 0; i < csboyut; i++)
		{
			temp_dizi[dizi[i] - min]++;
		}
		for (i = min; i <= max; i++)
		{
			for (j = 0; j < temp_dizi[i - min]; j++)
			{
				dizi[son++] = i;
			}
		}
		delete[] temp_dizi;
	}


	void ciktilar() {
		std::cout << "Sıralanmış dizi: \n";
		for (int i = 0; i < csboyut; i++)
			std::cout << dizi[i] << " ";
		std::cout << "\n";
	}
};


int main()
{
	setlocale(LC_ALL, "Turkish");
	std::cout << "Sisteme hoşgeldiniz. Bir seçenek seçiniz:\n";
	int mainMenuSecenek;
	char sortingSecim;
	do {
		std::cout << "1 - Çift Bağlı Liste\n2 - Stack\n3 - Dairesel Kuyruk\n4 - QuickSort Sıralama\n";
		std::cout << "5 - InsertionSort Sıralama\n6 - MergeSort Sıralama\n7 - CountingSort Sıralama\n0 - Programdan çıkış\n";
		std::cout << "Seçiminiz: ";
		std::cin >> mainMenuSecenek;

		if (mainMenuSecenek == 1)
		{
			system("CLS");
			std::cout << "---------\nÇift Bağlı Liste kodu başlatılıyor\n---------\n\n";
			int dllRoot, dllData, dllMenuSecim;
			std::cout << "DoublyLinkedList kök verisini giriniz: ";
			std::cin >> dllRoot;

			Onur_DLL* dip = new Onur_DLL(dllRoot);
			do {

				std::cout << "1 - Başa ekleme\n2 - Sona ekleme\n3 - Araya ekleme\n4 - Baştan silme\n5 - Sondan silme\n6 - Aradan silme\n7 - Yazdırma\n0 - Programdan çıkış\n";
				std::cout << "Seçiminiz: ";
				std::cin >> dllMenuSecim;
				std::cout << "\n";

				if (dllMenuSecim == 1)
				{
					std::cout << "Başa eklenecek veriyi girin: ";
					std::cin >> dllData;
					Onur_DLL* ekle = new Onur_DLL(dllData);
					dip = dip->basaadd(dip, ekle);
					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 2)
				{
					std::cout << "Sona eklenecek veriyi girin: ";
					std::cin >> dllData;
					Onur_DLL* ekle = new Onur_DLL(dllData);
					dip = dip->sonaadd(dip, ekle);
					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 3)
				{
					int dllAfterData;
					std::cout << "Hangi veriden sonra ekleneceğini giriniz:";
					std::cin >> dllAfterData;
					std::cout << "Araya eklenecek veriyi girin: ";
					std::cin >> dllData;
					Onur_DLL* ekle = new Onur_DLL(dllData);
					dip = dip->arayaadd(dip, ekle, dllAfterData);
					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 4)
				{
					dip = dip->bastanremove(dip);

					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 5)
				{
					dip = dip->sondanremove(dip);
					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 6)
				{
					int dllAfterData;
					std::cout << "Hangi verinin silineceğini giriniz:";
					std::cin >> dllAfterData;
					dip = dip->aradanremove(dip, dllAfterData);
					dip->ciktilar(dip);
				}

				else if (dllMenuSecim == 7)
				{
					dip->ciktilar(dip);
				}

				else
				{
					system("CLS");
					break;

				}
			} while (dllMenuSecim >= 1 && dllMenuSecim <= 7);
		}
		else if (mainMenuSecenek == 2)
		{
			system("CLS");
			std::cout << "---------\nStack kodu başlatılıyor\n---------\n\n";
			Can_stack can_stack;
			int stackMenu;

			do
			{
				std::cout << "1 - Push\n2 - Pop\n3 - Yazdır\n0 - Programdan Çıkış\nSeçiminiz: ";
				std::cin >> stackMenu;
				if (stackMenu == 1)
				{
					int stack_veriPush, stack_veriPushCount;
					std::cout << "Kaç adet veri Pushlamak istiyorsunuz?: ";
					std::cin >> stack_veriPushCount;
					std::cout << "Pushlanacak veriyi/verileri giriniz:";

					for (int i = 0; i < stack_veriPushCount; i++)
					{
						std::cin >> stack_veriPush;
						can_stack.push(stack_veriPush);
					}
					can_stack.ciktilarir();
				}

				else if (stackMenu == 2)
				{
					int stack_veripop;
					std::cout << "Kaç adet veri Poplamak istiyorsunuz?: ";
					std::cin >> stack_veripop;
					for (int i = 0; i < stack_veripop; i++)
					{
						can_stack.pop();
					}
					can_stack.ciktilarir();


				}

				else if (stackMenu == 3)
				{
					can_stack.ciktilarir();
				}

				else
				{
					system("CLS");
					break;
				}
			} while (stackMenu >= 1 && stackMenu <= 3);
		}
		else if (mainMenuSecenek == 3)
		{
			system("CLS");
			std::cout << "---------\nDairesel Kuyruk kodu başlatılıyor\n---------\n\n";
			int cqMenu;
			int cqboyut;
			std::cout << "CircularQueue Dizinin Boyutunu Giriniz:";
			std::cin >> cqboyut;
			Can_circularqueue can_circularqueue(cqboyut);

			do
			{
				std::cout << "1 - Enque\n2 - Deque\n3 - Yazdır\n0 - Programdan Çıkış\nSeçiminiz: ";
				std::cin >> cqMenu;
				if (cqMenu == 1)
				{
					int cq_veri, cq_veriCount;
					std::cout << "Kaç adet veri ekleyeceksiniz?: ";
					std::cin >> cq_veriCount;
					std::cout << "Pushlanacak veriyi/verileri giriniz:";

					for (int i = 0; i < cq_veriCount; i++)
					{
						std::cin >> cq_veri;
						can_circularqueue.enque(cq_veri);
					}
					can_circularqueue.ciktilar();
				}

				else if (cqMenu == 2)
				{
					int cq_veri;
					std::cout << "Kaç adet veri çıkarmak istiyorsunuz?: ";
					std::cin >> cq_veri;
					for (int i = 0; i < cq_veri; i++)
					{
						can_circularqueue.deque();
					}
					can_circularqueue.ciktilar();


				}

				else if (cqMenu == 3)
				{
					can_circularqueue.ciktilar();
				}

				else
				{
					system("CLS");
					break;
				}

			} while (cqMenu >= 1 && cqMenu <= 3);

		}
		else if (mainMenuSecenek == 4)
		{
			system("CLS");
			std::cout << "---------\nQuickSort kodu başlatılıyor\n---------\n\n";
			do {
				int qsboyut;
				std::cout << "Quicksort dizi boyutu giriniz:";
				std::cin >> qsboyut;
				Erte_QuickSort erte_quicksort(qsboyut);
				erte_quicksort.atama();
				erte_quicksort.SıralamaIslemi(0, qsboyut - 1);
				erte_quicksort.ciktilar();

				std::cout << "\nTekrar Sıralama Yapmak istiyor musunuz?\nE - Evet\nH - Hayır\nSeçiminiz: ";
				std::cin >> sortingSecim;
				if (sortingSecim == 'e' || sortingSecim == 'E') { std::cout << "\n"; }

				else { system("CLS"); break; }
			} while (sortingSecim == 'E' || sortingSecim == 'e');
		}

		else if (mainMenuSecenek == 5)
		{
			system("CLS");
			std::cout << "---------\nInsertionSort kodu başlatılıyor\n---------\n\n";
			do {
				int isboyut;
				std::cout << "InsertionSort dizi boyutu giriniz:";
				std::cin >> isboyut;
				Erte_InsertionSort erte_insertionsort(isboyut);
				erte_insertionsort.atama();
				erte_insertionsort.SiralamaIslemi();
				erte_insertionsort.ciktilar();

				std::cout << "\nTekrar Sıralama Yapmak istiyor musunuz?\nE - Evet\nH - Hayır\nSeçiminiz: ";
				std::cin >> sortingSecim;
				if (sortingSecim == 'e' || sortingSecim == 'E') { std::cout << "\n"; }

				else { system("CLS"); break; }
			} while (sortingSecim == 'E' || sortingSecim == 'e');
		}

		else if (mainMenuSecenek == 6)
		{
			system("CLS");
			std::cout << "---------\nMergeSort kodu başlatılıyor\n---------\n\n";
			do {
				int msboyut;
				std::cout << "MergeSort dizi boyutu giriniz: ";
				std::cin >> msboyut;
				Kin_MergeSort kin_mergesort(msboyut);
				kin_mergesort.atama();
				kin_mergesort.SiralamaIslemi(0, msboyut - 1);
				kin_mergesort.ciktilar();
				std::cout << "\nTekrar Sıralama Yapmak istiyor musunuz?\nE - Evet\nH - Hayır\nSeçiminiz: ";
				std::cin >> sortingSecim;
				if (sortingSecim == 'e' || sortingSecim == 'E') { std::cout << "\n"; }

				else { system("CLS"); break; }
			} while (sortingSecim == 'E' || sortingSecim == 'e');
		}

		else if (mainMenuSecenek == 7)
		{
			system("CLS");
			std::cout << "---------\nCountingSort kodu başlatılıyor\n---------\n\n";
			do {
				int csboyut;
				std::cout << "CountingSort dizi boyutu giriniz: ";
				std::cin >> csboyut;
				Kin_CountingSort kin_countingsort(csboyut);
				kin_countingsort.atama();
				kin_countingsort.SiralamaIslemi();
				kin_countingsort.ciktilar();
				std::cout << "\nTekrar Sıralama Yapmak istiyor musunuz?\nE - Evet\nH - Hayır\nSeçiminiz: ";
				std::cin >> sortingSecim;
				if (sortingSecim == 'e' || sortingSecim == 'E') { std::cout << "\n"; }

				else { system("CLS"); break; }
			} while (sortingSecim == 'E' || sortingSecim == 'e');
		}

		else
		{
			system("CLS");
			break;
		}
	} while (mainMenuSecenek >= 1 && mainMenuSecenek <= 7);
	return 0;
}


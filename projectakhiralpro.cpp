#include<bits/stdc++.h>


using namespace std;
	
	FILE *f;
	
	void cari_judul();
	void cari_tanggal();
	void cari_jam_film();
	void cari_harga_tiket();
	void cari_bioskop();
	void urut_judul();
	void urut_tanggal();
	void urut_bioskop();
	void urut_harga();
	
	int total = 0, pilih_input, pilih_cari, jumlah_film, simpanindex[100], jum_index = 0, a = 0, pilih_urut;
	string bioskop;
	char cari_film[30], cari_tanggal_film[12], jam_film[8];
	int cari_harga_film;
	
	struct jenis
	{
		char judul[30], tanggal[12];
		int harga;
		char jam[8];
		string bioskop;
	}pemasukan[100], temp;
	
int main()
{

	do
	{
		system("cls");
		cout << "=== Jadwal Film  !!! ===" << endl;
		cout << endl;
		cout << "MENU : " << endl;
		cout << " 1. Input Jadwal\n 2. Cari Jadwal\n 3. Urut Jadwal\n 4. Keluar\n";
		cout << "Pilih : "; cin >> pilih_input;
		
		switch(pilih_input)
		{
			case 1 :
				cout << "=== Barang Masuk ===" << endl;
				cout << endl;
				f = fopen("PROJEK.txt","w");
				cout << "Masukkan Jumlah Jadwal : "; cin >> jumlah_film;
				for(int i = 0; i < jumlah_film; i++)
				{
					cout << i+1 << ". Judul Film" << " 	: ";
					cin.ignore();
					cin.getline(pemasukan[i+total].judul,sizeof(pemasukan[i].judul));
					cout << "   Tanggal	: ";
					cin.ignore(0);
					cin.getline(pemasukan[i+total].tanggal,sizeof(pemasukan[i].tanggal));
					cout << "   Jam		: ";
					cin.ignore(0);
					cin.getline(pemasukan[i+total].jam,sizeof(pemasukan[i].jam));
					cout << "   Bioskop 	: ";
					getline(cin,pemasukan[i+total].bioskop);
					cout << "   Harga Tiket	: " << "Rp "; cin >> pemasukan[i+total].harga;
					cout << endl; 
				}
				cout << endl;
				
				total += jumlah_film;
				fwrite((char*)&pemasukan, sizeof(pemasukan),1,f);
				fwrite(&jumlah_film, sizeof(jumlah_film), 1, f);
				fwrite(&total, sizeof(total),1,f);
				fclose(f);
			break;
			
			case 2 :
				cout << "=== Cari Jadwal ===" << endl;
				cout << "Cari Menurut : " << endl;
				cout << " 1. Judul \n 2. Tanggal\n 3. Jam\n 4. Bioskop\n 5. Harga Tiket\n 6. Keluar\n";
				cout << "Pilih : "; cin >> pilih_cari;
				
				if(pilih_cari == 1)
				{
					cari_judul();
				}
				
				else if(pilih_cari == 2)
				{
					cari_tanggal();
				}
				
				else if(pilih_cari == 3)
				{
					cari_jam_film();
				}
				
				else if(pilih_cari == 4)
				{
					cari_bioskop();
				}
				else if(pilih_cari == 5)
				{
					cari_harga_tiket();
				}
				else if(pilih_cari == 6)
				{
					exit(0);
				}
				else
				{
					cout << "  |-----------------------------------------------------|" << endl;
					cout << "  |      Maaf... Pilihan yang anda masukan Salah !      |" << endl;
					cout << "  | Silahkan coba lagi dengan mengklik ENTER 1x lagi :) |" << endl;
					cout << "  |-----------------------------------------------------|" << endl;
					system("pause");
				}
			break;
			
			case 3 :
				cout << "=== Urut Barang ===" << endl;
				cout << "Urut Menurut : " << endl;
				cout << " 1. Judul Film\n 2. Tanggal\n 3. Bioskop\n 4. Harga\n 5. Keluar\n";
				cout << "Pilih : ";
				cin >> pilih_urut;
				
				if(pilih_urut == 1)
				{
					urut_judul();
				}
				
				else if(pilih_urut == 2)
				{
					urut_tanggal();
				}
				else if(pilih_urut == 3)
				{
					urut_bioskop();
				}
				else if(pilih_urut== 4)
				{
					urut_harga();
				}
				else if(pilih_urut == 5)
				{
					exit(0);
				}
				else
				{
					cout << "  |-----------------------------------------------------|" << endl;
					cout << "  |      Maaf... Pilihan yang anda masukan Salah !      |" << endl;
					cout << "  | Silahkan coba lagi dengan mengklik ENTER 1x lagi :) |" << endl;
					cout << "  |-----------------------------------------------------|" << endl;
					system("pause");
				}
			break;
			
			case 4 :
				exit(0);
			break;
				
			default :
				cout << "  |-----------------------------------------------------|" << endl;
				cout << "  |      Maaf... Pilihan yang anda masukan Salah !      |" << endl;
				cout << "  | Silahkan coba lagi dengan mengklik ENTER 1x lagi :) |" << endl;
				cout << "  |-----------------------------------------------------|" << endl;
				system("pause");
			break;
			}
	}
	while(pilih_input != 4 && pilih_cari != 5);
}

void cari_judul()
{
	cout << "=== Cari Judul Film  ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	cout << "Masukan Judul Film : ";
	cin.ignore();
	cin.getline(cari_film,sizeof(cari_film));
					
	for(int i = 0; i < total; i++)
	{
	    while(strcmp(pemasukan[i].judul,cari_film)==0)
	    {
	        a = 1;
	      	simpanindex[jum_index] = i;
	        jum_index++;
	        break;
		}
	}
						
	if( a == 1)
	{
		for( int j = 0; j < jum_index; j++)
		{
			cout << " === Jadwal Di Temukan === " << endl;
			cout << endl;
			cout << "Judul Film      : " << pemasukan[simpanindex[j]].judul << endl;
            cout << "Tanggal		: " << pemasukan[simpanindex[j]].tanggal << endl;
            cout << "Jam		: " << pemasukan[simpanindex[j]].jam << endl;
            cout << "Bioskop     	: " << pemasukan[simpanindex[j]].bioskop << endl;
            cout << "Harga	 Tiket  : Rp " << pemasukan[simpanindex[j]].harga << endl;
	    }
        cout << endl;
	}
	else
	{
		cout << "Jadwal tidak ditemukan, Silahkan ketik dengan benar :)" << endl;
		cout << "=== TERIMA KASIH ===" << endl;
	}
	system("pause");
	a = 0;
	jum_index = 0;
	fclose(f);
}

void cari_tanggal()
{
	cout << "=== Cari Tanggal Tiket ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	cout << "Masukan Tanggal Tiket  : ";
	cin.ignore();
	cin.getline(cari_tanggal_film,sizeof(cari_tanggal_film));
					
	for(int i = 0; i < total; i++)
	{
		while(strcmp(pemasukan[i].tanggal,cari_tanggal_film)==0)
	   	{
		    a = 1;
		    simpanindex[jum_index] = i;
		    jum_index++;
		   	break;
		}
	}
						
		if( a == 1)
		{
			for( int j = 0; j < jum_index; j++)
			{
				cout << " === Jadwal Di Temukan === " << endl;
				cout << endl;
				cout << "Judul Film    : " << pemasukan[simpanindex[j]].judul << endl;
				cout << "Tanggal	   : " << pemasukan[simpanindex[j]].tanggal << endl;
				cout << "Jam		   : " << pemasukan[simpanindex[j]].jam << endl;
				cout << "Bioskop       : " << pemasukan[simpanindex[j]].bioskop << endl;
				cout << "Harga	 Tiket : Rp " << pemasukan[simpanindex[j]].harga << endl;
			}
			cout << endl;
		}
		else
		{
			cout << "Jadwal tidak ditemukan, Silahkan ketik dengan benar :)" << endl;
			cout << "=== TERIMA KASIH ===" << endl;
		}
		system("pause");
		a = 0;
		jum_index = 0;
		fclose(f);
}

void cari_jam_film()
{
	cout << "=== Cari Jam Film ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	cout << " Masukan Jam Film : ";
	cin.ignore();
	cin.getline(jam_film,sizeof(jam_film));
					
	for(int i = 0; i < total; i++)
	{
	   while(strcmp(pemasukan[i].jam,jam_film)==0)
	   {
			a = 1;
			simpanindex[jum_index] = i;
   			jum_index++;
			break;
		}
	}	
						
	if( a == 1)
	{
		for( int j = 0; j < jum_index; j++)
		{
			cout << " === Jadwal Di Temukan === " << endl;
			cout << endl;
			cout << "Judul Film      : " << pemasukan[simpanindex[j]].judul << endl;
            cout << "Tanggal		: " << pemasukan[simpanindex[j]].tanggal << endl;
            cout << "Jam		: " << pemasukan[simpanindex[j]].jam << endl;
            cout << "Bioskop     	: " << pemasukan[simpanindex[j]].bioskop << endl;
            cout << "Harga	 Tiket  : Rp " << pemasukan[simpanindex[j]].harga << endl;	 
         }
		cout << endl;
	}
        
	else
	{
		cout << "Jadwal tidak ditemukan, Silahkan ketik dengan benar :)" << endl;
		cout << "=== TERIMA KASIH ===" << endl;
	}
	system("pause");
	a = 0;
	jum_index = 0;
	fclose(f);
}

void cari_bioskop()
{
	cout << "=== Cari Bioskop ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	cout << "Masukan Nama Bioskop :  ";
	cin.ignore();
	getline(cin,bioskop);
					
	for(int i = 0; i < total; i++)
	{
		while(pemasukan[i].bioskop == bioskop)
	    {
		   	a = 1;
			simpanindex[jum_index] = i;
   			jum_index++;
			break;
		}
	}	
						
	if( a == 1)
	{
		for( int j = 0; j < jum_index; j++)
		{
			cout << " === Jadwal Di Temukan === " << endl;
			cout << endl;
			cout << "Judul Film      : " << pemasukan[simpanindex[j]].judul << endl;
            cout << "Tanggal		: " << pemasukan[simpanindex[j]].tanggal << endl;
            cout << "Jam		: " << pemasukan[simpanindex[j]].jam << endl;
            cout << "Bioskop     	: " << pemasukan[simpanindex[j]].bioskop << endl;
            cout << "Harga	 Tiket  : Rp " << pemasukan[simpanindex[j]].harga << endl;
	    }
        cout << endl;
	}
        
	else
	{
		cout << "Jadwal tidak ditemukan, Silahkan ketik dengan benar :)" << endl;
		cout << "=== TERIMA KASIH ===" << endl;
	}
	system("pause");
	a = 0;
	jum_index = 0;
	fclose(f);	
}

void urut_judul()
{
	cout << "=== Urut Judul Film ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	for(int i=0; i<total; i++)
	{
      for(int j=i+1; j<total; j++)
      {
		 for(int k=0; k<30; k++)
		 {
			if(pemasukan[i].judul[k] < pemasukan[j].judul[k])
			{
				break;
			}
			else if(pemasukan[i].judul[k] > pemasukan[j].judul[k])
			{
				temp = pemasukan[i];
				pemasukan[i] = pemasukan[j];
				pemasukan[j] = temp;
				break;
			}
		}
      }
     }
     cout << "Hasil Pengurutan : \n";
     for(int i=0; i < total; i++)
     {
		 cout << endl;
		cout << "Jadwal  " << i+1 << endl;
		cout << endl;
		cout << "Judul Film      : " << pemasukan[i].judul << endl;
		cout << "Tanggal		: " << pemasukan[i].tanggal << endl;
		cout << "Jam	  	: " << pemasukan[i].jam << endl;
		cout << "Bioskop     	: " << pemasukan[i].bioskop << endl;
		cout << "Harga	 Tiket  : Rp " << pemasukan[i].harga << endl;
     }
     cout << endl;
	system("pause");
	fclose(f);
}

void urut_tanggal()
{
	cout << "=== Urut Tanggal ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	for(int i=0; i<total; i++)
	{
      for(int j=i+1; j<total; j++)
      {
		 for(int k=0; k<10; k++)
		 {
			if(pemasukan[i].tanggal[k] < pemasukan[j].tanggal[k])
			{
				break;
			}
			else if(pemasukan[i].tanggal[k] > pemasukan[j].tanggal[k])
			{
				temp = pemasukan[i];
				pemasukan[i] = pemasukan[j];
				pemasukan[j] = temp;
				break;
			}
		}
      }
     }
     cout << "Hasil Pengurutan : \n";
     for(int i=0; i < total; i++)
     {
		cout << "Jadwal  " << i+1 << endl;
		cout << endl;
		cout << "Judul Film     : " << pemasukan[i].judul << endl;
		cout << "Tanggal		: " << pemasukan[i].tanggal << endl;
		cout << "Jam		   	: " << pemasukan[i].jam << endl;
		cout << "Bioskop     	:  " << pemasukan[i].bioskop << endl;
		cout << "Harga	 Tiket  :  Rp " << pemasukan[i].harga << endl;
     }
     cout << endl;
	system("pause");
	fclose(f);
}

void urut_harga()
{
	cout << "=== Urut Harga Tiket ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	for(int i = 0; i < total - 1; i++)
	{
		for(int j = i+1; j < total; j++)
		{
			int c = i;
			if(pemasukan[c].harga > pemasukan[j].harga)
			{
				c = j;
			}
			temp = pemasukan[c];
			pemasukan[c] = pemasukan[i];
			pemasukan[i] = temp;
		}
	}
	
	cout << "Hasil Pengurutan : \n";
	for(int i=0; i < total; i++)
     {
		cout << "Jadwal  " << i+1 << endl;
		cout << endl;
		cout << "Judul Film     : " << pemasukan[i].judul << endl;
		cout << "Tanggal		: " << pemasukan[i].tanggal << endl;
		cout << "Jam		   	: " << pemasukan[i].jam << endl;
		cout << "Bioskop     	: " << pemasukan[i].bioskop << endl;
		cout << "Harga	 Tiket  : Rp " << pemasukan[i].harga << endl;
	}
	cout << endl;
	system("pause");
	fclose(f);
}

void cari_harga_tiket()
{
	cout << "=== Cari Harga Tiket ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	cout << "Masukan Harga Tiket : Rp ";
	cin >> cari_harga_film;
					
	for(int i = 0; i < total; i++)
	{
		while(pemasukan[i].harga == cari_harga_film)
	    {
		   	a = 1;
			simpanindex[jum_index] = i;
   			jum_index++;
			break;
		}
	}	
						
	if( a == 1)
	{
		for( int j = 0; j < jum_index; j++)
		{
			cout << " === Jadwal Di Temukan === " << endl;
			cout << endl;
			cout << "Judul Film      : " << pemasukan[simpanindex[j]].judul << endl;
            cout << "Tanggal		: " << pemasukan[simpanindex[j]].tanggal << endl;
            cout << "Jam		: " << pemasukan[simpanindex[j]].jam << endl;
            cout << "Bioskop     	: " << pemasukan[simpanindex[j]].bioskop << endl;
            cout << "Harga	 Tiket  : Rp " << pemasukan[simpanindex[j]].harga << endl;
	    }
        cout << endl;
	}
        
	else
	{
		cout << "Jadwal tidak ditemukan, Silahkan ketik dengan benar :)" << endl;
		cout << "=== TERIMA KASIH ===" << endl;
	}
	system("pause");
	a = 0;
	jum_index = 0;
	fclose(f);
}

void urut_bioskop()
{
	cout << "=== Urut Bioskop ===" << endl;
	cout << endl;
	
	f = fopen("PROJEK.txt","r");
	fread((char*)&pemasukan, sizeof(pemasukan),1,f);
	fread(&jumlah_film, sizeof(jumlah_film), 1, f);
	fread(&total, sizeof(total),1,f);
	
	for(int i = 0; i < total - 1; i++)
	{
		for(int j = i+1; j < total; j++)
		{
			int c = i;
			if(pemasukan[c].bioskop > pemasukan[j].bioskop)
			{
				c = j;
			}
			temp = pemasukan[c];
			pemasukan[c] = pemasukan[i];
			pemasukan[i] = temp;
		}
	}
	
	cout << "Hasil Pengurutan : \n";
	for(int i=0; i < total; i++)
     {
		cout << "Jadwal  " << i+1 << endl;
		cout << endl;
		cout << "Judul Film     : " << pemasukan[i].judul << endl;
		cout << "Tanggal		: " << pemasukan[i].tanggal << endl;
		cout << "Jam		   	: " << pemasukan[i].jam << endl;
		cout << "Bioskop     	: " << pemasukan[i].bioskop << endl;
		cout << "Harga	 Tiket  : Rp " << pemasukan[i].harga << endl;
     }
    cout << endl;
	system("pause");
	fclose(f);
}

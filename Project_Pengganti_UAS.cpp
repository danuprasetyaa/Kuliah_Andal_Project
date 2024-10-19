#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Movie {
    string title;
    string theater;
};

int calculateAge(int birthYear)
{
    int currentYear = 2024;
    return currentYear - birthYear;
}

Movie getMovie(string filmType, string showTime)
{
    if (showTime == "10.00") {
        if (filmType == "Anak-Anak") return {"Dora the Movie", "Teater 1"};
        if (filmType == "Komedi Remaja") return {"SuperMan is Dad", "Teater 2"};
        return {"tidak beroperasi", "kosong"};
    } else if (showTime == "13.20") {
        if (filmType == "Anak-Anak") return {"Naruto The Movie", "Teater 1"};
        if (filmType == "Komedi Remaja") return {"Pocong Pink", "Teater 3"};
        return {"satu atap dua cinta", "Teater 3"};
    } else if (showTime == "18.20") {
        if (filmType == "Anak-Anak") return {"Doraemon The Movie", "Teater 1"};
        if (filmType == "Komedi Remaja") return {"Tahu Bunting Cinta", "Teater 1"};
        return {"the rainBow", "Teater 2"};
    } else if (showTime == "21.20") {
        if (filmType == "Anak-Anak") return {"tidak Beroperasi", "Kosong"};
        if (filmType == "Komedi Remaja") return {"Horor Merah Jambu", "Teater 3"};
        return {"IronMan", "Teater 1"};
    }
    return {"", ""};
}

double calculateTotal(int ticketPrice, int seatPrice, int quantity, bool discount)
{
    double total = (ticketPrice + seatPrice) * quantity;
    if (discount && quantity >= 3) {
        total -= 5000;
    }
    return total;
}

int main()
{
    string name, filmType, showTime, seatType, nim;
    int birthYear, age, quantity;
    double ticketPrice, seatPrice, total, cash, change;
    bool repeat;

    do {
        cout << "Masukkan Nama Pelanggan: ";
        getline(cin, name);
        cout << "Masukkan Tanggal Lahir (Tahun): ";
        cin >> birthYear;
        age = calculateAge(birthYear);
        cin.ignore(); 

        
        cout << "Pilih Jenis Film (Anak-Anak / Komedi Remaja / Dewasa): ";
        getline(cin, filmType);

        
        cout << "Pilih Jam Putar (10.00 / 13.20 / 18.20 / 21.20): ";
        getline(cin, showTime);

        
        Movie selectedMovie = getMovie(filmType, showTime);
        cout << "Judul Film: " << selectedMovie.title << ", Teater: " << selectedMovie.theater << endl;

        if (filmType == "Anak-Anak") ticketPrice = 25000;
        else if (filmType == "Komedi Remaja") ticketPrice = 35000;
        else if (filmType == "Dewasa") ticketPrice = 40000;
        else ticketPrice = 0;

        cout << "Pilih Jenis Bangku (VIP / Bisnis / Reguler): ";
        getline(cin, seatType);
        if (seatType == "VIP") seatPrice = 20000;
        else if (seatType == "Bisnis") seatPrice = 10000;
        else seatPrice = 0;


        cout << "Masukkan Jumlah Tiket: ";
        cin >> quantity;

        bool discountApplicable = (quantity >= 3);
        total = calculateTotal(ticketPrice, seatPrice, quantity, discountApplicable);

        cout << "Masukkan Uang: ";
        cin >> cash;
        change = cash - total;


        cout << "\nDAFTAR PEMESANAN TIKET 12\n";
        cout << "=========================\n";
        cout << "Nama Pemesan: " << name << endl;
        cout << "Tanggal Lahir: " << birthYear << endl;
        cout << "Usia: " << age << " tahun" << endl;
        cout << "Jenis Film: " << filmType << endl;
        cout << "Jam Tayang: " << showTime << endl;
        cout << "Judul Film: " << selectedMovie.title << endl;
        cout << "Teater: " << selectedMovie.theater << endl;
        cout << "Jenis Bangku: " << seatType << endl;
        cout << "Jumlah Tiket: " << quantity << endl;
        cout << "Total Bayar: Rp " << fixed << setprecision(2) << total << endl;
        cout << "Uang: Rp " << cash << endl;
        cout << "Kembalian: Rp " << change << endl;

        cout << "\nApakah Anda ingin memesan lagi? (y/n): ";
        char repeatChoice;
        cin >> repeatChoice;
        repeat = (repeatChoice == 'y' || repeatChoice == 'Y');


        cout << "Masukkan NIM (atau tekan enter untuk lanjut): ";
        cin.ignore();
        getline(cin, nim);
        if (!nim.empty()) {
            cout << "Programmer: [Danu Prasetya]" << endl; 
        }

    } while (repeat);

    return 0;
}


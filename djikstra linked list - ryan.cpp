// RYAN FAHLEPY SINAGA
// 320210401021

#include <iostream> // Library untuk input-output stream
#include <limits> // Library untuk mendapatkan batasan maksimal dari tipe data

using namespace std; // Menggunakan namespace std

// Deklarasi struct edge
struct edge;

// Deklarasi struct node
struct node {
    string nama; // Data anggota struct berupa nama bertipe string
    edge *link; // Pointer ke struct edge
};

// Deklarasi struct edge
struct edge {
    int jarak; // Data anggota struct berupa jarak bertipe integer
    node *tujuan; // Pointer ke struct node
    edge *next; // Pointer ke struct edge berikutnya
};

// Pointer graph yang menunjuk ke node baru
node *graph = new node();

// Fungsi untuk menampilkan graf
void display(node *current) {
    edge *temp = current->link; // Mendeklarasikan pointer temp yang menunjuk ke link node saat ini
    while (temp != NULL) { // Melakukan loop selama temp tidak NULL
        if (temp->tujuan != NULL) { // Jika tujuan dari temp tidak NULL
            cout << current->nama << " -> " << temp->tujuan->nama << " = " << temp->jarak << endl; // Menampilkan nama node saat ini, tujuan, dan jarak
        }
        if (temp->tujuan != NULL) { // Jika tujuan dari temp tidak NULL
            display(temp->tujuan); // Rekursi untuk menampilkan node tujuan
        }
        temp = temp->next; // Menggeser temp ke link berikutnya
    }
}

// Fungsi untuk mencari jalur terpendek menuju suatu node
void search(node *insert) {
    node *node1 = insert; // Pointer node1 menunjuk ke node yang akan dimulai pencarian
    node *node2 = new node; // Pointer node2 menunjuk ke node kedua yang dibandingkan
    node2->link = insert->link->next; // Menyamakan link node2 dengan link node1 ke-2
    
    int dist[2] = {0,0}; // Array untuk menyimpan jarak terpendek dari masing-masing node
    string jalan[2][4] = {{"0","0","0","0"},{"0","0","0","0"}}; // Array untuk menyimpan jalur terpendek
    
    int route; // Variabel untuk menentukan rute terpendek
    
    while (node1->link != NULL && node2->link != NULL) { // Melakukan loop selama kedua node masih memiliki link
        if (node1->link->jarak + dist[0] <= node2->link->jarak + dist[1]) { // Jika jarak dari node1 lebih kecil atau sama dengan jarak dari node2
            route = 0; // Mengatur rute ke 0
            dist[route] += node1->link->jarak; // Menambahkan jarak dari node1 ke jarak terpendek
            node1 = node1->link->tujuan; // Pindah ke node tujuan dari node1
            for (int i = 0;; i++) { // Loop untuk mencari posisi kosong pada array jalan
                if (jalan[route][i] == "0") { // Jika ada posisi kosong pada array
                    jalan[route][i] = node1->nama; // Isi posisi kosong dengan nama node
                    break; // Keluar dari loop
                }
            }
        } else if (node1->link->jarak + dist[0] > node2->link->jarak + dist[1]) { // Jika jarak dari node1 lebih besar dari jarak node2
            route = 1; // Mengatur rute ke 1
            dist[route] += node2->link->jarak; // Menambahkan jarak dari node2 ke jarak terpendek
            node2 = node2->link->tujuan; // Pindah ke node tujuan dari node2
            for (int i = 0;; i++) { // Loop untuk mencari posisi kosong pada array jalan
                if (jalan[route][i] == "0") { // Jika ada posisi kosong pada array
                    jalan[route][i] = node2->nama; // Isi posisi kosong dengan nama node
                    break; // Keluar dari loop
                }
            }
        }
    }
    
    // Menampilkan informasi jalur terpendek
    cout << endl << "Jalur terpendek menuju E " << endl;
    cout << insert->nama; // Menampilkan nama node awal
    for (int i = 0; i < 4; i++) { // Loop untuk menampilkan jalur terpendek
        if (jalan[route][i] != "0") { // Jika ada jalur yang tersimpan
            cout << " -> " << jalan[route][i]; // Menampilkan jalur
        }
    }
    cout << " = " << dist[route]; // Menampilkan jarak terpendek
}

int main() { // Fungsi utama program
    graph->nama = "A"; // Menamai node awal A
    
    // Node tujuan B
    node *tujuan = new node(); // Mendeklarasikan node tujuan baru
    tujuan->nama = "B"; // Menamai node tujuan B
    
    // Link dari A ke B
    edge *link = new edge(); // Mendeklarasikan link baru
    link->jarak = 50; // Menentukan jarak antara node awal dan node tujuan
    link->tujuan = tujuan; // Mengaitkan link dengan node tujuan
    graph->link = link; // Mengaitkan link dengan node awal
    
    // Node tujuan C
    tujuan = new node(); // Mendeklarasikan node tujuan baru
    tujuan->nama = "C"; // Menamai node tujuan C
    
    // Link dari A ke C
    link = new edge(); // Mendeklarasikan link baru
    link->jarak = 10; // Menentukan jarak antara node awal dan node tujuan
    link->tujuan = tujuan; // Mengaitkan link dengan node tujuan
    graph->link->next = link; // Mengaitkan link dengan node awal
    
    // Node tujuan D
    tujuan = new node(); // Mendeklarasikan node tujuan baru
    tujuan->nama = "D"; // Menamai node tujuan D
    
    // Link dari C ke D
    link = new edge(); // Mendeklarasikan link baru
    link->jarak = 30; // Menentukan jarak antara node awal dan node tujuan
    link->tujuan = tujuan; // Mengaitkan link dengan node tujuan

    graph->link->tujuan->link = link; // Mengaitkan link dengan node awal
    
    // Node tujuan E
    tujuan = new node(); // Mendeklarasikan node tujuan baru
    tujuan->nama = "E"; // Menamai node tujuan E
    
    // Link dari D ke E
    link = new edge(); // Mendeklarasikan link baru
    link->jarak = 40; // Menentukan jarak antara node awal dan node tujuan
    link->tujuan = tujuan; // Mengaitkan link dengan node tujuan
    graph->link->tujuan->link->next = link; // Mengaitkan link dengan node awal
    
    // Link dari C ke E
    tujuan = new node(); // Mendeklarasikan node tujuan baru
    tujuan->nama = "E"; // Menamai node tujuan E
    link = new edge(); // Mendeklarasikan link baru
    link->jarak = 20; // Menentukan jarak antara node awal dan node tujuan
    link->tujuan = tujuan; // Mengaitkan link dengan node tujuan
    graph->link->next->tujuan->link = link; // Mengaitkan link dengan node awal
    
    display(graph); // Menampilkan graf
    
    search(graph); // Mencari jalur terpendek menuju E
    
    cout << endl << "Selesai"; // Menampilkan pesan "Selesai"
    
    return 0; // Mengembalikan nilai 0 untuk menandakan program berakhir
}

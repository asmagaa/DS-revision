#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Implementacja kopca typu max-heap (rodzic >= dzieci)
// Kopiec przechowujemy w wektorze, gdzie dla węzła na indeksie i:
// - lewe dziecko: 2*i + 1
// - prawe dziecko: 2*i + 2
// - rodzic: (i-1)/2

class MaxHeap {
private:
    vector<int> heap;

    // Funkcja pomocnicza do wyświetlania kopca
    void displayHeap() {
        cout << "Kopiec: [";
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i];
            if (i < heap.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    // Funkcja pomocnicza - zwraca indeks lewego dziecka
    int leftChild(int i) { return 2 * i + 1; }

    // Funkcja pomocnicza - zwraca indeks prawego dziecka
    int rightChild(int i) { return 2 * i + 2; }

    // Funkcja pomocnicza - zwraca indeks rodzica
    int parent(int i) { return (i - 1) / 2; }

public:
    // ============================================================================
    // POZIOM 1: ŁATWY
    // ============================================================================

    // TODO 1: Zaimplementuj funkcję wstawiającą element do kopca
    // Kroki:
    // 1. Dodaj element na koniec wektora (heap.push_back)
    // 2. Przesuwaj element w górę (heapify up), dopóki własność kopca nie jest spełniona
    //    - Porównuj z rodzicem: parent(i)
    //    - Jeśli element > rodzic, zamień miejscami i kontynuuj
    //    - Zatrzymaj się gdy element <= rodzic lub dotrzesz do korzenia
    void insert(int value) {
        // UZUPEŁNIJ KOD
    }

    // TODO 2: Zaimplementuj funkcję zwracającą maksymalny element (bez usuwania)
    // W max-heap maksymalny element to zawsze korzeń (heap[0])
    // Zwróć -1 jeśli kopiec jest pusty
    int getMax() {
        // UZUPEŁNIJ KOD
    }

    // TODO 3: Zaimplementuj funkcję zwracającą rozmiar kopca
    // Po prostu zwróć rozmiar wektora heap
    int size() {
        // UZUPEŁNIJ KOD
    }

    // ============================================================================
    // POZIOM 2: ŚREDNI
    // ============================================================================

    // TODO 4: Zaimplementuj funkcję usuwającą i zwracającą maksymalny element
    // Kroki:
    // 1. Jeśli kopiec pusty, zwróć -1
    // 2. Zapisz wartość korzenia (max)
    // 3. Przenieś ostatni element na miejsce korzenia
    // 4. Usuń ostatni element (heap.pop_back)
    // 5. Przesuwaj nowy korzeń w dół (heapify down):
    //    - Znajdź większe dziecko
    //    - Jeśli dziecko > rodzic, zamień miejscami
    //    - Kontynuuj dla dziecka
    // 6. Zwróć zapisaną wartość max
    int extractMax() {
        // UZUPEŁNIJ KOD
    }

    // TODO 5: Zaimplementuj funkcję naprawiającą własność kopca w dół od indeksu i
    // (heapify down dla poddrzewa zaczynającego się w i)
    // Używana w extractMax i buildHeap
    // Kroki:
    // 1. Znajdź indeksy lewego i prawego dziecka
    // 2. Znajdź największy element spośród: węzeł i, lewe dziecko, prawe dziecko
    // 3. Jeśli największy != i, zamień miejscami i wywołaj rekurencyjnie dla dziecka
    void heapifyDown(int i) {
        // UZUPEŁNIJ KOD
    }

    // TODO 6: Zaimplementuj funkcję budującą kopiec z dowolnej tablicy
    // Otrzymujesz wektor wartości i musisz przekształcić go w poprawny kopiec
    // Kroki:
    // 1. Skopiuj wszystkie elementy z arr do heap
    // 2. Wywołaj heapifyDown dla wszystkich węzłów niebędących liśćmi
    //    - Zacznij od ostatniego rodzica: (heap.size()/2 - 1)
    //    - Idź wstecz do korzenia (indeks 0)
    // Złożoność: O(n)
    void buildHeap(vector<int>& arr) {
        // UZUPEŁNIJ KOD
    }

    // ============================================================================
    // POZIOM 3: TRUDNY
    // ============================================================================

    // TODO 7: Zaimplementuj funkcję scalającą dwa kopce
    // Otrzymujesz drugi kopiec i musisz scalić go z obecnym
    // Kroki:
    // 1. Dodaj wszystkie elementy z other.heap do bieżącego heap (użyj insert w pętli)
    //    LUB efektywniej:
    // 2. Dołącz wszystkie elementy z other.heap na koniec bieżącego heap
    // 3. Wywołaj buildHeap aby naprawić własność kopca
    void merge(MaxHeap& other) {
        // UZUPEŁNIJ KOD
    }

    // TODO 8: Zaimplementuj funkcję zwracającą k-ty największy element
    // NIE USUWAJ elementów z kopca (użyj kopii)
    // Kroki:
    // 1. Utwórz kopię obecnego kopca
    // 2. Wykonaj extractMax k razy na kopii
    // 3. Zwróć k-ty wyciągnięty element
    // Zwróć -1 jeśli k > rozmiar kopca
    int kthLargest(int k) {
        // UZUPEŁNIJ KOD
    }

    // TODO 9: Zaimplementuj funkcję sprawdzającą czy wektor reprezentuje poprawny max-heap
    // Dla każdego węzła na indeksie i sprawdź czy:
    // - heap[i] >= heap[leftChild(i)] (jeśli lewe dziecko istnieje)
    // - heap[i] >= heap[rightChild(i)] (jeśli prawe dziecko istnieje)
    // Zwróć true jeśli wszystkie węzły spełniają warunek, false w przeciwnym razie
    bool isValidHeap() {
        // UZUPEŁNIJ KOD
    }

    // ========================================================================
    // Funkcje pomocnicze do testów (gotowe)
    // ========================================================================

    void display() {
        displayHeap();
    }

    vector<int> getHeapArray() {
        return heap;
    }

    void clear() {
        heap.clear();
    }
};

int main() {
    // ========================================================================
    // TESTY POZIOMU 1
    // ========================================================================

    cout << "=== POZIOM 1: LATWY ===\n\n";

    // Test 1: insert
    cout << "Test 1: insert\n";
    MaxHeap h1;
    h1.insert(10);
    h1.insert(20);
    h1.insert(15);
    h1.insert(30);
    h1.insert(40);
    cout << "Po wstawieniu: 10, 20, 15, 30, 40\n";
    h1.display();
    /*
    Oczekiwany wynik (jedna z możliwych reprezentacji):
    Kopiec: [40, 30, 15, 10, 20]
    (40 na szczycie, dzieci <= rodzic)
    */
    cout << endl;

    // Test 2: getMax
    cout << "Test 2: getMax\n";
    cout << "Maksymalny element: " << h1.getMax() << endl;
    cout << "Kopiec po getMax (nie zmieniony): ";
    h1.display();
    /*
    Oczekiwany wynik:
    Maksymalny element: 40
    Kopiec po getMax (nie zmieniony): [40, 30, 15, 10, 20]
    */
    cout << endl;

    // Test 3: size
    cout << "Test 3: size\n";
    cout << "Rozmiar kopca: " << h1.size() << endl;
    /*
    Oczekiwany wynik:
    Rozmiar kopca: 5
    */
    cout << endl;

    // ========================================================================
    // TESTY POZIOMU 2
    // ========================================================================

    cout << "=== POZIOM 2: SREDNI ===\n\n";

    // Test 4: extractMax
    cout << "Test 4: extractMax\n";
    MaxHeap h2;
    h2.insert(10);
    h2.insert(20);
    h2.insert(15);
    h2.insert(30);
    h2.insert(40);
    cout << "Kopiec poczatkowy: ";
    h2.display();

    cout << "Usunieto max: " << h2.extractMax() << endl;
    cout << "Kopiec po usunieciu: ";
    h2.display();

    cout << "Usunieto max: " << h2.extractMax() << endl;
    cout << "Kopiec po usunieciu: ";
    h2.display();
    /*
    Oczekiwany wynik:
    Kopiec poczatkowy: [40, 30, 15, 10, 20]
    Usunieto max: 40
    Kopiec po usunieciu: [30, 20, 15, 10]
    Usunieto max: 30
    Kopiec po usunieciu: [20, 10, 15]
    */
    cout << endl;

    // Test 5 i 6: buildHeap (korzysta z heapifyDown)
    cout << "Test 5 i 6: buildHeap\n";
    MaxHeap h3;
    vector<int> arr = {4, 10, 3, 5, 1, 8, 7, 2, 9, 6};
    cout << "Tablica wejsciowa: [4, 10, 3, 5, 1, 8, 7, 2, 9, 6]\n";
    h3.buildHeap(arr);
    cout << "Kopiec po buildHeap: ";
    h3.display();
    cout << "Maksymalny element: " << h3.getMax() << endl;
    /*
    Oczekiwany wynik (jedna z możliwych reprezentacji):
    Tablica wejsciowa: [4, 10, 3, 5, 1, 8, 7, 2, 9, 6]
    Kopiec po buildHeap: [10, 9, 8, 5, 6, 3, 7, 2, 4, 1]
    Maksymalny element: 10
    */
    cout << endl;

    // ========================================================================
    // TESTY POZIOMU 3
    // ========================================================================

    cout << "=== POZIOM 3: TRUDNY ===\n\n";

    // Test 7: merge
    cout << "Test 7: merge\n";
    MaxHeap h4, h5;
    h4.insert(50);
    h4.insert(30);
    h4.insert(20);
    cout << "Kopiec 1: ";
    h4.display();

    h5.insert(40);
    h5.insert(25);
    h5.insert(15);
    cout << "Kopiec 2: ";
    h5.display();

    h4.merge(h5);
    cout << "Kopiec po scaleniu: ";
    h4.display();
    cout << "Maksymalny element po scaleniu: " << h4.getMax() << endl;
    /*
    Oczekiwany wynik:
    Kopiec 1: [50, 30, 20]
    Kopiec 2: [40, 25, 15]
    Kopiec po scaleniu: [50, 40, 20, 30, 25, 15] (lub inna poprawna reprezentacja)
    Maksymalny element po scaleniu: 50
    */
    cout << endl;

    // Test 8: kthLargest
    cout << "Test 8: kthLargest\n";
    MaxHeap h6;
    vector<int> arr2 = {7, 10, 4, 3, 20, 15};
    h6.buildHeap(arr2);
    cout << "Kopiec: ";
    h6.display();
    cout << "1-szy najwiekszy: " << h6.kthLargest(1) << endl;
    cout << "2-gi najwiekszy: " << h6.kthLargest(2) << endl;
    cout << "3-ci najwiekszy: " << h6.kthLargest(3) << endl;
    cout << "Kopiec po kthLargest (nie zmieniony): ";
    h6.display();
    /*
    Oczekiwany wynik:
    Kopiec: [20, 10, 15, 3, 7, 4]
    1-szy najwiekszy: 20
    2-gi najwiekszy: 15
    3-ci najwiekszy: 10
    Kopiec po kthLargest (nie zmieniony): [20, 10, 15, 3, 7, 4]
    */
    cout << endl;

    // Test 9: isValidHeap
    cout << "Test 9: isValidHeap\n";
    MaxHeap h7;
    h7.insert(50);
    h7.insert(30);
    h7.insert(20);
    h7.insert(10);
    cout << "Kopiec 1: ";
    h7.display();
    cout << "Czy poprawny kopiec? " << (h7.isValidHeap() ? "TAK" : "NIE") << endl;

    // Ręcznie stwórz niepoprawny kopiec (do testów)
    MaxHeap h8;
    vector<int> invalid = {10, 20, 30}; // Niepoprawny: dzieci > rodzic
    h8.buildHeap(invalid); // buildHeap naprawi to
    cout << "Kopiec 2 (po buildHeap): ";
    h8.display();
    cout << "Czy poprawny kopiec? " << (h8.isValidHeap() ? "TAK" : "NIE") << endl;
    /*
    Oczekiwany wynik:
    Kopiec 1: [50, 30, 20, 10]
    Czy poprawny kopiec? TAK
    Kopiec 2 (po buildHeap): [30, 20, 10]
    Czy poprawny kopiec? TAK
    */

    return 0;
}

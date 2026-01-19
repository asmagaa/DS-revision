#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Implementacja kopca typu max-heap (rodzic >= dzieci)
// Kopiec przechowujemy w tablicy, gdzie dla węzła na indeksie i:
// - lewe dziecko: 2*i + 1
// - prawe dziecko: 2*i + 2
// - rodzic: (i-1)/2

typedef struct {
    int* heap;
    int size;
    int capacity;
} MaxHeap;

// Funkcja pomocnicza do wyświetlania kopca
void displayHeap(MaxHeap* h) {
    printf("Kopiec: [");
    for (int i = 0; i < h->size; i++) {
        printf("%d", h->heap[i]);
        if (i < h->size - 1) printf(", ");
    }
    printf("]\n");
}

// Funkcja pomocnicza - zwraca indeks lewego dziecka
int leftChild(int i) { return 2 * i + 1; }

// Funkcja pomocnicza - zwraca indeks prawego dziecka
int rightChild(int i) { return 2 * i + 2; }

// Funkcja pomocnicza - zwraca indeks rodzica
int parent(int i) { return (i - 1) / 2; }

// Funkcja inicjalizująca kopiec
void initHeap(MaxHeap* h, int capacity) {
    h->heap = (int*)malloc(capacity * sizeof(int));
    h->size = 0;
    h->capacity = capacity;
}

// Funkcja zwalniająca pamięć
void freeHeap(MaxHeap* h) {
    free(h->heap);
    h->heap = NULL;
    h->size = 0;
    h->capacity = 0;
}

// Funkcja powiększająca pojemność kopca
void resizeHeap(MaxHeap* h) {
    h->capacity *= 2;
    h->heap = (int*)realloc(h->heap, h->capacity * sizeof(int));
}

// swap do pomocy w insercie i heapify downie
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ============================================================================
// POZIOM 1: ŁATWY
// ============================================================================

// TODO 1: Zaimplementuj funkcję wstawiającą element do kopca
// Kroki:
// 1. Sprawdź czy trzeba powiększyć tablicę (size >= capacity)
// 2. Dodaj element na koniec tablicy
// 3. Zwiększ size
// 4. Przesuwaj element w górę (heapify up), dopóki własność kopca nie jest spełniona
//    - Porównuj z rodzicem: parent(i)
//    - Jeśli element > rodzic, zamień miejscami i kontynuuj
//    - Zatrzymaj się gdy element <= rodzic lub dotrzesz do korzenia
void insert(MaxHeap* h, int value) 
{
    if (h->size >= h->capacity)
    {
        resizeHeap(h);
    }

    h->heap[h->size] = value;
    int i = h->size;
    h->size++;

    while (i > 0 && h->heap[i] > h->heap[parent(i)])
    {
        swap(&h->heap[i], &h->heap[parent(i)]);
        i = parent(i);
    }
}

// TODO 2: Zaimplementuj funkcję zwracającą maksymalny element (bez usuwania)
// W max-heap maksymalny element to zawsze korzeń (heap[0])
// Zwróć -1 jeśli kopiec jest pusty
int getMax(MaxHeap* h) 
{
    if (h->size == 0)
    {
        return -1;
    }

    return h->heap[0];
}

// TODO 3: Zaimplementuj funkcję zwracającą rozmiar kopca
// Po prostu zwróć pole size
int getSize(MaxHeap* h) 
{
    return h->size;
}

// ============================================================================
// POZIOM 2: ŚREDNI
// ============================================================================

// heapify down trzeba bedzie wczesniej zadeklarowac bo uzyje w extractcie

void heapifyDown(MaxHeap* h, int i)
{
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < h->size && h->heap[left] > h->heap[largest])
    {
        largest = left;
    }
    if (right < h->size && h->heap[right] > h->heap[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&h->heap[i], &h->heap[largest]);
        heapifyDown(h, largest);
    }
}

// TODO 4: Zaimplementuj funkcję usuwającą i zwracającą maksymalny element
// Kroki:
// 1. Jeśli kopiec pusty, zwróć -1
// 2. Zapisz wartość korzenia (max)
// 3. Przenieś ostatni element na miejsce korzenia
// 4. Zmniejsz size
// 5. Przesuwaj nowy korzeń w dół (heapify down)
// 6. Zwróć zapisaną wartość max
int extractMax(MaxHeap* h) 
{
    if (h->size == 0)
    {
        return -1;
    }

    int maxValue = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;

    if (h->size > 0)
    {
        heapifyDown(h, 0);
    }
    
    return maxValue;
}

// TODO 5: Zaimplementuj funkcję naprawiającą własność kopca w dół od indeksu i
// (heapify down dla poddrzewa zaczynającego się w i)
// Używana w extractMax i buildHeap
// Kroki:
// 1. Znajdź indeksy lewego i prawego dziecka
// 2. Znajdź największy element spośród: węzeł i, lewe dziecko, prawe dziecko
// 3. Jeśli największy != i, zamień miejscami i wywołaj rekurencyjnie dla dziecka

// na gorze (113)

// TODO 6: Zaimplementuj funkcję budującą kopiec z dowolnej tablicy
// Otrzymujesz tablicę wartości i jej rozmiar - musisz przekształcić ją w poprawny kopiec
// Kroki:
// 1. Skopiuj wszystkie elementy z arr do heap (sprawdź capacity!)
// 2. Ustaw size na n
// 3. Wywołaj heapifyDown dla wszystkich węzłów niebędących liśćmi
//    - Zacznij od ostatniego rodzica: (size/2 - 1)
//    - Idź wstecz do korzenia (indeks 0)
// Złożoność: O(n)
void buildHeap(MaxHeap* h, int* arr, int n) 
{
    while (h->capacity < n)
    {
        resizeHeap(h);
    }

    for (int i = 0; i < n; i++)
    {
        h->heap[i] = arr[i];
    }

    h->size = n;

    for (int i = h->size / 2 - 1; i >= 0; i--) 
    {
        heapifyDown(h, i);
    }
}

// ============================================================================
// POZIOM 3: TRUDNY
// ============================================================================

// TODO 7: Zaimplementuj funkcję scalającą dwa kopce
// Otrzymujesz drugi kopiec i musisz scalić go z obecnym
// Kroki:
// 1. Upewnij się że bieżący kopiec ma wystarczającą pojemność
// 2. Skopiuj wszystkie elementy z other do bieżącego kopca
// 3. Zaktualizuj size
// 4. Wywołaj heapifyDown dla wszystkich węzłów niebędących liśćmi
void mergeHeap(MaxHeap* h, MaxHeap* other) 
{
    while (h->capacity < h->size + other->size)
    {
        resizeHeap(h);
    }

    for (int i = 0; i < other->size; i++)
    {
        h->heap[h->size + i] = other->heap[i];
    }

    h->size += other->size;

    for (int i = h->size / 2 - 1; i >= 0; i--)
    {
        heapifyDown(h, i);
    }
}

// TODO 8: Zaimplementuj funkcję zwracającą k-ty największy element
// NIE USUWAJ elementów z kopca (użyj kopii)
// Kroki:
// 1. Utwórz kopię obecnego kopca (nowy MaxHeap + skopiuj tablicę)
// 2. Wykonaj extractMax k razy na kopii
// 3. Zapisz k-ty wyciągnięty element
// 4. Zwolnij pamięć kopii
// 5. Zwróć zapisaną wartość
// Zwróć -1 jeśli k > rozmiar kopca lub k <= 0
int kthLargest(MaxHeap* h, int k) 
{
    if (k <= 0 || k > h->size)
    {
        return -1;
    }

    MaxHeap copy;
    initHeap(&copy, h->capacity);
    copy.size = h->size;

    for (int i = 0; i < h->size; i++)
    {
        copy.heap[i] = h->heap[i];
    }

    int result = -1;
    for (int i = 0; i < k; i++)
    {
        result = extractMax(&copy);
    }

    freeHeap(&copy);

    return result;
}

// TODO 9: Zaimplementuj funkcję sprawdzającą czy tablica reprezentuje poprawny max-heap
// Dla każdego węzła na indeksie i sprawdź czy:
// - heap[i] >= heap[leftChild(i)] (jeśli lewe dziecko istnieje)
// - heap[i] >= heap[rightChild(i)] (jeśli prawe dziecko istnieje)
// Zwróć true jeśli wszystkie węzły spełniają warunek, false w przeciwnym razie
bool isValidHeap(MaxHeap* h) 
{
    for (int i = 0; i < h->size; i++)
    {
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < h->size && h->heap[i] < h->heap[left])
        {
            return false;
        }

        if (right < h->size && h->heap[i] < h->heap[right]) 
        {
            return false;
        }
    }

    return true;
}

// ========================================================================
// Funkcje pomocnicze do testów (gotowe)
// ========================================================================

void display(MaxHeap* h) {
    displayHeap(h);
}

void clearHeap(MaxHeap* h) {
    h->size = 0;
}

int main() {
    // ========================================================================
    // TESTY POZIOMU 1
    // ========================================================================

    printf("=== POZIOM 1: LATWY ===\n\n");

    // Test 1: insert
    printf("Test 1: insert\n");
    MaxHeap h1;
    initHeap(&h1, 10);
    insert(&h1, 10);
    insert(&h1, 20);
    insert(&h1, 15);
    insert(&h1, 30);
    insert(&h1, 40);
    printf("Po wstawieniu: 10, 20, 15, 30, 40\n");
    display(&h1);
    /*
    Oczekiwany wynik (jedna z możliwych reprezentacji):
    Kopiec: [40, 30, 15, 10, 20]
    (40 na szczycie, dzieci <= rodzic)
    */
    printf("\n");

    // Test 2: getMax
    printf("Test 2: getMax\n");
    printf("Maksymalny element: %d\n", getMax(&h1));
    printf("Kopiec po getMax (nie zmieniony): ");
    display(&h1);
    /*
    Oczekiwany wynik:
    Maksymalny element: 40
    Kopiec po getMax (nie zmieniony): [40, 30, 15, 10, 20]
    */
    printf("\n");

    // Test 3: getSize
    printf("Test 3: size\n");
    printf("Rozmiar kopca: %d\n", getSize(&h1));
    /*
    Oczekiwany wynik:
    Rozmiar kopca: 5
    */
    printf("\n");

    freeHeap(&h1);

    // ========================================================================
    // TESTY POZIOMU 2
    // ========================================================================

    printf("=== POZIOM 2: SREDNI ===\n\n");

    // Test 4: extractMax
    printf("Test 4: extractMax\n");
    MaxHeap h2;
    initHeap(&h2, 10);
    insert(&h2, 10);
    insert(&h2, 20);
    insert(&h2, 15);
    insert(&h2, 30);
    insert(&h2, 40);
    printf("Kopiec poczatkowy: ");
    display(&h2);

    printf("Usunieto max: %d\n", extractMax(&h2));
    printf("Kopiec po usunieciu: ");
    display(&h2);

    printf("Usunieto max: %d\n", extractMax(&h2));
    printf("Kopiec po usunieciu: ");
    display(&h2);
    /*
    Oczekiwany wynik:
    Kopiec poczatkowy: [40, 30, 15, 10, 20]
    Usunieto max: 40
    Kopiec po usunieciu: [30, 20, 15, 10]
    Usunieto max: 30
    Kopiec po usunieciu: [20, 10, 15]
    */
    printf("\n");

    freeHeap(&h2);

    // Test 5 i 6: buildHeap (korzysta z heapifyDown)
    printf("Test 5 i 6: buildHeap\n");
    MaxHeap h3;
    initHeap(&h3, 20);
    int arr[] = {4, 10, 3, 5, 1, 8, 7, 2, 9, 6};
    int arr_size = 10;
    printf("Tablica wejsciowa: [4, 10, 3, 5, 1, 8, 7, 2, 9, 6]\n");
    buildHeap(&h3, arr, arr_size);
    printf("Kopiec po buildHeap: ");
    display(&h3);
    printf("Maksymalny element: %d\n", getMax(&h3));
    /*
    Oczekiwany wynik (jedna z możliwych reprezentacji):
    Tablica wejsciowa: [4, 10, 3, 5, 1, 8, 7, 2, 9, 6]
    Kopiec po buildHeap: [10, 9, 8, 5, 6, 3, 7, 2, 4, 1]
    Maksymalny element: 10
    */
    printf("\n");

    freeHeap(&h3);

    // ========================================================================
    // TESTY POZIOMU 3
    // ========================================================================

    printf("=== POZIOM 3: TRUDNY ===\n\n");

    // Test 7: mergeHeap
    printf("Test 7: merge\n");
    MaxHeap h4, h5;
    initHeap(&h4, 10);
    initHeap(&h5, 10);
    insert(&h4, 50);
    insert(&h4, 30);
    insert(&h4, 20);
    printf("Kopiec 1: ");
    display(&h4);

    insert(&h5, 40);
    insert(&h5, 25);
    insert(&h5, 15);
    printf("Kopiec 2: ");
    display(&h5);

    mergeHeap(&h4, &h5);
    printf("Kopiec po scaleniu: ");
    display(&h4);
    printf("Maksymalny element po scaleniu: %d\n", getMax(&h4));
    /*
    Oczekiwany wynik:
    Kopiec 1: [50, 30, 20]
    Kopiec 2: [40, 25, 15]
    Kopiec po scaleniu: [50, 40, 20, 30, 25, 15] (lub inna poprawna reprezentacja)
    Maksymalny element po scaleniu: 50
    */
    printf("\n");

    freeHeap(&h4);
    freeHeap(&h5);

    // Test 8: kthLargest
    printf("Test 8: kthLargest\n");
    MaxHeap h6;
    initHeap(&h6, 10);
    int arr2[] = {7, 10, 4, 3, 20, 15};
    int arr2_size = 6;
    buildHeap(&h6, arr2, arr2_size);
    printf("Kopiec: ");
    display(&h6);
    printf("1-szy najwiekszy: %d\n", kthLargest(&h6, 1));
    printf("2-gi najwiekszy: %d\n", kthLargest(&h6, 2));
    printf("3-ci najwiekszy: %d\n", kthLargest(&h6, 3));
    printf("Kopiec po kthLargest (nie zmieniony): ");
    display(&h6);
    /*
    Oczekiwany wynik:
    Kopiec: [20, 10, 15, 3, 7, 4]
    1-szy najwiekszy: 20
    2-gi najwiekszy: 15
    3-ci najwiekszy: 10
    Kopiec po kthLargest (nie zmieniony): [20, 10, 15, 3, 7, 4]
    */
    printf("\n");

    freeHeap(&h6);

    // Test 9: isValidHeap
    printf("Test 9: isValidHeap\n");
    MaxHeap h7;
    initHeap(&h7, 10);
    insert(&h7, 50);
    insert(&h7, 30);
    insert(&h7, 20);
    insert(&h7, 10);
    printf("Kopiec 1: ");
    display(&h7);
    printf("Czy poprawny kopiec? %s\n", isValidHeap(&h7) ? "TAK" : "NIE");

    // Ręcznie stwórz niepoprawny kopiec (do testów)
    MaxHeap h8;
    initHeap(&h8, 10);
    int invalid[] = {10, 20, 30}; // Niepoprawny: dzieci > rodzic
    buildHeap(&h8, invalid, 3); // buildHeap naprawi to
    printf("Kopiec 2 (po buildHeap): ");
    display(&h8);
    printf("Czy poprawny kopiec? %s\n", isValidHeap(&h8) ? "TAK" : "NIE");
    /*
    Oczekiwany wynik:
    Kopiec 1: [50, 30, 20, 10]
    Czy poprawny kopiec? TAK
    Kopiec 2 (po buildHeap): [30, 20, 10]
    Czy poprawny kopiec? TAK
    */

    freeHeap(&h7);
    freeHeap(&h8);

    return 0;
}

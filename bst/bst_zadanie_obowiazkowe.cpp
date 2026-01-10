#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode();
    newNode->val = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// ============================================================================
// POZIOM 1: ŁATWY (OCENA 3)
// ============================================================================

// TODO 1: Zaimplementuj funkcję wstawiającą wartość do BST
// Wskazówka: Jeśli drzewo jest puste (root == nullptr), utwórz nowy węzeł
// Jeśli value < root->val, wstaw do lewego poddrzewa
// Jeśli value > root->val, wstaw do prawego poddrzewa
// Funkcja powinna zwracać wskaźnik na korzeń
TreeNode* insert(TreeNode* root, int value) {
    // UZUPEŁNIJ KOD
}

// TODO 2: Zaimplementuj funkcję wyszukującą wartość w BST
// Zwróć true jeśli wartość istnieje, false jeśli nie
bool search(TreeNode* root, int value) {
    // UZUPEŁNIJ KOD
}

// TODO 3: Zaimplementuj funkcję zliczającą wszystkie węzły w drzewie
int countNodes(TreeNode* root) {
    // UZUPEŁNIJ KOD
}

// TODO 4: Zaimplementuj in-order traversal (lewo, korzeń, prawo)
// To wypisze elementy BST w kolejności rosnącej!
void inOrderTraversal(TreeNode* root) {
    // UZUPEŁNIJ KOD
}

// ============================================================================
// POZIOM 2: ŚREDNI (OCENA 4)
// ============================================================================

// TODO 5: Zaimplementuj funkcję znajdującą MINIMALNĄ wartość w BST
TreeNode* findMin(TreeNode* root) {
    // UZUPEŁNIJ KOD
}

// TODO 6: Zaimplementuj funkcję obliczającą wysokość drzewa
// Wysokość = najdłuższa ścieżka od korzenia do liścia
// Wysokość pustego drzewa = 0, wysokość drzewa z jednym węzłem = 1
int height(TreeNode* root) {
    // UZUPEŁNIJ KOD
    // Wskazówka: wysokość = 1 + max(wysokość lewego, wysokość prawego)
}

// TODO 7: Zaimplementuj funkcję zliczającą liście w drzewie
// Liść = węzeł bez dzieci (left == nullptr && right == nullptr)
int countLeaves(TreeNode* root) {
    // UZUPEŁNIJ KOD
}

// TODO 8: Zaimplementuj funkcję obliczającą sumę wszystkich wartości w drzewie
int sum(TreeNode* root) {
    // UZUPEŁNIJ KOD
}

// ============================================================================
// POZIOM 3: TRUDNY (OCENA 5)
// ============================================================================

// TODO 9: Zaimplementuj funkcję usuwającą węzeł z BST
// Mamy 3 przypadki:
// PRZYPADEK 1: Węzeł nie ma dzieci (jest liściem)
//    -> Po prostu usuń węzeł (zwróć nullptr)
// PRZYPADEK 2: Węzeł ma jedno dziecko
//    -> Zastąp węzeł jego dzieckiem
// PRZYPADEK 3: Węzeł ma dwoje dzieci
//    -> Znajdź następnika (najmniejszy element w PRAWYM poddrzewie)
//    -> Skopiuj wartość następnika do usuwanego węzła
//    -> Usuń następnika z prawego poddrzewa (rekurencyjnie)
TreeNode* deleteNode(TreeNode* root, int value) {
    // UZUPEŁNIJ KOD
}

// TODO 10: Zaimplementuj funkcję tworzącą lustrzane odbicie drzewa
// Zamień miejscami lewe i prawe poddrzewo dla każdego węzła
TreeNode* mirror(TreeNode* root) {
    // UZUPEŁNIJ KOD
    // 1. Jeśli root == nullptr, zwróć nullptr
    // 2. Rekurencyjnie odbij lewe i prawe poddrzewo
    // 3. Zamień miejscami left i right
}

// TODO 11: Zaimplementuj funkcję sprawdzającą, czy drzewo jest poprawnym BST
// UWAGA: Nie wystarczy sprawdzić, czy left->val < root->val < right->val!
// Użyj pomocniczej funkcji z zakresami min/max
bool isBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    // UZUPEŁNIJ KOD
    // 1. Jeśli root == nullptr, zwróć true
    // 2. Jeśli root->val <= minVal lub root->val >= maxVal, zwróć false
    // 3. Sprawdź rekurencyjnie lewe poddrzewo z zakresem [minVal, root->val]
    // 4. Sprawdź rekurencyjnie prawe poddrzewo z zakresem [root->val, maxVal]
}

bool isBST(TreeNode* root) {
    return isBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// ============================================================================
// POZIOM 4: BARDZO TRUDNY (OCENA 6)
// ============================================================================

// TODO 12: Zaimplementuj funkcję znajdującą k-ty najmniejszy element w BST
// k jest 1-based (k=1 to najmniejszy, k=2 to drugi najmniejszy, itd.)
// Wskazówka: Użyj in-order traversal i licznika
void findKthSmallestHelper(TreeNode* root, int k, int& counter, int& result) {
    // UZUPEŁNIJ KOD
    // 1. Jeśli root == nullptr, return
    // 2. Odwiedź lewe poddrzewo
    // 3. Zwiększ counter, jeśli counter == k, zapisz result = root->val
    // 4. Odwiedź prawe poddrzewo (tylko jeśli jeszcze nie znaleźliśmy)
}

int findKthSmallest(TreeNode* root, int k) {
    int counter = 0;
    int result = -1;
    findKthSmallestHelper(root, k, counter, result);
    return result;
}

// TODO 13: Zaimplementuj funkcję znajdującą Najniższy Wspólny Przodek (LCA)
// LCA to najniższy węzeł, który jest przodkiem obu p i q
// Własność BST: jeśli p i q są po różnych stronach root, to root jest LCA
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    // UZUPEŁNIJ KOD
    // Przypadki:
    // - root == nullptr: zwróć nullptr
    // - Jeśli p i q są mniejsze od root->val, szukaj w lewym poddrzewie
    // - Jeśli p i q są większe od root->val, szukaj w prawym poddrzewie
    // - W przeciwnym razie root jest LCA (p i q są po różnych stronach)
}

// TODO 14: Zaimplementuj funkcję konwertującą posortowaną tablicę na zbalansowane BST
// Zbalansowane BST = różnica wysokości lewego i prawego poddrzewa <= 1
// Algorytm:
// 1. Znajdź środkowy element tablicy i zrób go korzeniem
// 2. Rekurencyjnie zbuduj lewe poddrzewo z lewej połowy
// 3. Rekurencyjnie zbuduj prawe poddrzewo z prawej połowy
TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    // UZUPEŁNIJ KOD
    // Przypadek bazowy: start > end, zwróć nullptr
    // 1. Znajdź środek: mid = start + (end - start) / 2
    // 2. Utwórz węzeł z arr[mid]
    // 3. Rekurencyjnie zbuduj lewe poddrzewo z [start, mid-1]
    // 4. Rekurencyjnie zbuduj prawe poddrzewo z [mid+1, end]
}

int main() {
    // ========================================================================
    // TESTY POZIOMU 1 (OCENA 3)
    // ========================================================================

    cout << "=== POZIOM 1: LATWY (OCENA 3) ===\n\n";

    // Test 1-4: insert, search, countNodes, inOrderTraversal
    cout << "Test 1-4: Podstawowe operacje\n";
    TreeNode* root1 = nullptr;
    root1 = insert(root1, 50);
    root1 = insert(root1, 30);
    root1 = insert(root1, 70);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);
    root1 = insert(root1, 60);
    root1 = insert(root1, 80);

    /*
    Struktura drzewa:
           50
          /  \
        30    70
       / \   / \
      20 40 60 80
    */

    cout << "Drzewo (in-order): ";
    inOrderTraversal(root1);
    cout << endl;
    cout << "Oczekiwane: 20 30 40 50 60 70 80\n";

    cout << "Liczba wezlow: " << countNodes(root1) << endl;
    cout << "Oczekiwana: 7\n";

    cout << "Czy jest 40? " << (search(root1, 40) ? "TAK" : "NIE") << endl;
    cout << "Oczekiwane: TAK\n";
    cout << "Czy jest 100? " << (search(root1, 100) ? "TAK" : "NIE") << endl;
    cout << "Oczekiwane: NIE\n\n";

    // ========================================================================
    // TESTY POZIOMU 2 (OCENA 4)
    // ========================================================================

    cout << "=== POZIOM 2: SREDNI (OCENA 4) ===\n\n";

    // Test 5: findMin
    cout << "Test 5: findMin\n";
    TreeNode* minNode = findMin(root1);
    cout << "Minimalna wartosc: " << (minNode ? minNode->val : -1) << endl;
    cout << "Oczekiwana: 20\n\n";

    // Test 6: height
    cout << "Test 6: height\n";
    cout << "Wysokosc drzewa: " << height(root1) << endl;
    cout << "Oczekiwana: 3\n\n";

    // Test 7: countLeaves
    cout << "Test 7: countLeaves\n";
    cout << "Liczba lisci: " << countLeaves(root1) << endl;
    cout << "Oczekiwana: 4 (20, 40, 60, 80)\n\n";

    // Test 8: sum
    cout << "Test 8: sum\n";
    cout << "Suma wszystkich wartosci: " << sum(root1) << endl;
    cout << "Oczekiwana: 350\n\n";

    // ========================================================================
    // TESTY POZIOMU 3 (OCENA 5)
    // ========================================================================

    cout << "=== POZIOM 3: TRUDNY (OCENA 5) ===\n\n";

    // Test 9: deleteNode
    cout << "Test 9: deleteNode\n";
    TreeNode* root2 = nullptr;
    root2 = insert(root2, 50);
    root2 = insert(root2, 30);
    root2 = insert(root2, 70);
    root2 = insert(root2, 20);
    root2 = insert(root2, 40);
    root2 = insert(root2, 60);
    root2 = insert(root2, 80);

    cout << "Drzewo przed usunieciem: ";
    inOrderTraversal(root2);
    cout << endl;

    root2 = deleteNode(root2, 20);  // usuń liść
    cout << "Po usunieciu 20 (lisc): ";
    inOrderTraversal(root2);
    cout << endl;
    cout << "Oczekiwane: 30 40 50 60 70 80\n";

    root2 = deleteNode(root2, 50);  // usuń węzeł z dwoma dziećmi
    cout << "Po usunieciu 50 (dwoje dzieci): ";
    inOrderTraversal(root2);
    cout << endl;
    cout << "Oczekiwane: 30 40 60 70 80\n\n";

    // Test 10: mirror
    cout << "Test 10: mirror\n";
    TreeNode* root3 = nullptr;
    root3 = insert(root3, 50);
    root3 = insert(root3, 30);
    root3 = insert(root3, 70);
    root3 = insert(root3, 20);
    root3 = insert(root3, 40);

    cout << "Przed odbiciem: ";
    inOrderTraversal(root3);
    cout << endl;

    root3 = mirror(root3);
    cout << "Po odbiciu: ";
    inOrderTraversal(root3);
    cout << endl;
    cout << "Oczekiwane: 70 50 40 30 20 (odwrotna kolejnosc)\n\n";

    // Test 11: isBST
    cout << "Test 11: isBST\n";
    TreeNode* root4 = nullptr;
    root4 = insert(root4, 50);
    root4 = insert(root4, 30);
    root4 = insert(root4, 70);

    cout << "Poprawne BST: " << (isBST(root4) ? "TAK" : "NIE") << endl;
    cout << "Oczekiwane: TAK\n";

    // Ręcznie tworzę niepoprawne BST
    TreeNode* root5 = createNode(10);
    root5->left = createNode(5);
    root5->right = createNode(15);
    root5->left->right = createNode(12);  // BŁĄD! 12 > 10

    cout << "Niepoprawne BST: " << (isBST(root5) ? "TAK" : "NIE") << endl;
    cout << "Oczekiwane: NIE\n\n";

    // ========================================================================
    // TESTY POZIOMU 4 (OCENA 6)
    // ========================================================================

    cout << "=== POZIOM 4: BARDZO TRUDNY (OCENA 6) ===\n\n";

    // Test 12: findKthSmallest
    cout << "Test 12: findKthSmallest\n";
    cout << "Drzewo (in-order): ";
    inOrderTraversal(root1);
    cout << endl;
    cout << "1-szy najmniejszy element: " << findKthSmallest(root1, 1) << endl;
    cout << "Oczekiwany: 20\n";
    cout << "3-ci najmniejszy element: " << findKthSmallest(root1, 3) << endl;
    cout << "Oczekiwany: 40\n";
    cout << "7-my najmniejszy element: " << findKthSmallest(root1, 7) << endl;
    cout << "Oczekiwany: 80\n\n";

    // Test 13: lowestCommonAncestor
    cout << "Test 13: lowestCommonAncestor\n";
    TreeNode* lca1 = lowestCommonAncestor(root1, 20, 40);
    cout << "LCA(20, 40): " << (lca1 ? lca1->val : -1) << endl;
    cout << "Oczekiwane: 30\n";

    TreeNode* lca2 = lowestCommonAncestor(root1, 20, 80);
    cout << "LCA(20, 80): " << (lca2 ? lca2->val : -1) << endl;
    cout << "Oczekiwane: 50\n";

    TreeNode* lca3 = lowestCommonAncestor(root1, 60, 80);
    cout << "LCA(60, 80): " << (lca3 ? lca3->val : -1) << endl;
    cout << "Oczekiwane: 70\n\n";

    // Test 14: sortedArrayToBST
    cout << "Test 14: sortedArrayToBST\n";
    int sortedArr[] = {10, 20, 30, 40, 50, 60, 70};
    int arrSize = 7;
    TreeNode* balancedTree = sortedArrayToBST(sortedArr, 0, arrSize - 1);

    cout << "Posortowana tablica: ";
    for (int i = 0; i < arrSize; i++) {
        cout << sortedArr[i] << " ";
    }
    cout << endl;

    cout << "Zbalansowane BST (in-order): ";
    inOrderTraversal(balancedTree);
    cout << endl;
    cout << "Wysokosc zbalansowanego drzewa: " << height(balancedTree) << endl;
    cout << "Oczekiwana wysokosc: 3 (minimalna dla 7 elementow)\n";
    cout << "Oczekiwana in-order: 10 20 30 40 50 60 70\n";

    return 0;
}

/* PODSUMOWANIE OCZEKIWANYCH WYNIKÓW:

=== POZIOM 1: LATWY (OCENA 3) ===
- In-order: 20 30 40 50 60 70 80
- Liczba węzłów: 7
- Search 40: TAK, Search 100: NIE

=== POZIOM 2: SREDNI (OCENA 4) ===
- Minimalna wartość: 20
- Wysokość: 3
- Liczba liści: 4
- Suma: 350

=== POZIOM 3: TRUDNY (OCENA 5) ===
- Po usunięciu 20: 30 40 50 60 70 80
- Po usunięciu 50: 30 40 60 70 80
- Po odbiciu: 70 50 40 30 20
- Poprawne BST: TAK, Niepoprawne: NIE

=== POZIOM 4: BARDZO TRUDNY (OCENA 6) ===
- K-ty najmniejszy: 1->20, 3->40, 7->80
- LCA(20,40): 30, LCA(20,80): 50, LCA(60,80): 70
- Zbalansowane BST wysokość: 3
*/

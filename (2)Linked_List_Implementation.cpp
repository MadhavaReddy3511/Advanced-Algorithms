#include <iostream>

// Define the structure for a node in the linked list
struct Node {
    int row, col;
    double value;
    Node* next;

    Node(int row, int col, double value) : row(row), col(col), value(value), next(nullptr) {}
};

// Define the class for the Sparse Matrix using Linked List
class SparseMatrix {
private:
    Node* head; // Pointer to the first node in the linked list
    int rows;
    int cols;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c), head(nullptr) {}

    ~SparseMatrix() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int row, int col, double value) {
        if (value == 0) return; // Only store non-zero elements

        Node* newNode = new Node(row, col, value);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void display() {
        int** fullMatrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            fullMatrix[i] = new int[cols]();
        }

        Node* current = head;
        while (current != nullptr) {
            fullMatrix[current->row][current->col] = current->value;
            current = current->next;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << fullMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Clean up dynamic array
        for (int i = 0; i < rows; i++) {
            delete[] fullMatrix[i];
        }
        delete[] fullMatrix;
    }
};

int main() {
    int rows, cols, num_elements;

    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    SparseMatrix matrix(rows, cols);

    std::cout << "Enter the number of non-zero elements: ";
    std::cin >> num_elements;

    for (int i = 0; i < num_elements; i++) {
        int row, col;
        double value;
        std::cout << "Enter row index, column index and value for element, seperated by space " << i + 1 << ": ";
        std::cin >> row >> col >> value;
        matrix.add(row, col, value);
    }

    std::cout << "Sparse Matrix:" << std::endl;
    matrix.display();

    return 0;
}

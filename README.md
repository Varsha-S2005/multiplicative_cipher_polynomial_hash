# Multiplicative Cipher & Custom Polynomial Hash (C++)

This project implements a secure communication simulation featuring a **Multiplicative Cipher** for encryption/decryption and a **Custom Polynomial Rolling Hash** for data integrity verification.

## 1. Deliverables
* **Encryption/Decryption:** Full implementation of the Multiplicative Cipher.
* **Custom Hashing:** A position-sensitive polynomial hash with a bit-mixing finalizer.
* **Round-Trip Script:** A test sequence demonstrating `Plaintext → Hash → Encrypt → Decrypt → Verify Hash`.
* **Key Validation:** Automated GCD check to ensure key eligibility.

---

## 2. Mathematical Theory

### The Multiplicative Cipher
The Multiplicative Cipher is a monoalphabetic substitution cipher where each letter's position ($P$) is transformed using a secret key ($k$):
* **Encryption:** $C = (P \times k) \pmod{26}$
* **Decryption:** $P = (C \times k^{-1}) \pmod{26}$

**The Coprime Requirement:** For the cipher to work, the key $k$ must be **coprime** to 26 ($gcd(k, 26) = 1$). If they share a common factor (like 2 or 13), multiple letters will map to the same ciphertext, making the message unrecoverable.

### The Custom Polynomial Hash
To ensure the message isn't tampered with, we use a **Polynomial Rolling Hash**. Unlike simple addition, this method is order-sensitive.
* **Formula:** $H = \sum (S[i] \times P^i) \pmod M$
* **Base ($P$):** 31 (A small prime to distribute characters).
* **Modulus ($M$):** $10^9 + 9$ (A large prime to prevent collisions).

---

## 3. Justification for using this Hash:

1.  **Position Sensitivity:** By multiplying each character by $P^i$, the hash ensures that "ACT" and "CAT" produce entirely different results, unlike simpler additive hashes.
2.  **Key-Based Salting:** The encryption key $k$ is used to initialize the hash. This binds the integrity check to the specific secret key.
3.  **The Avalanche Effect:** We implemented a `finalize()` function using **XOR-shifts** and the **MurmurHash3 constant** (`0x85ebca6b`). This ensures that changing a single bit in the message flips roughly 50% of the bits in the final hash, making it mathematically robust against patterns.
---

## 4. How to Run

1.  **Compile the code:**
    ```bash
    g++ -o cipher_task main.cpp
    ```
2.  **Run the executable:**
    ```bash
    ./cipher_task
    ```
3.  **Input:** Enter your message and a valid key (e.g., 3, 5, 7, 11, 15, 17, 19, 21, 23, 25).

---

## 5. Worked Examples:

#### Example 1: Standard Assignment Test
* **Plaintext:** `Cryptography CIA assignment`
* **Key:** `11`
* **Ciphertext:** `Wfejbyofajze WKA aqqkoncsnb`
* **Decrypted Message:** `Cryptography CIA assignment`
* **Original Hash:** `1832732454227500267`
* **Final Hash:** `1832732454227500267`
* **Verification:** The system successfully encrypted and decrypted the message. The original and final hashes match perfectly, confirming 100% data integrity.

#### Example 2: Sentence with Mixed Case and Spaces
* **Plaintext:** `Hello World we are implemeting Multiplicative Cipher`
* **Key:** `5`
* **Ciphertext:** `Judds Gshdp gu ahu oixduiurone Iwdroxdokarobu Koxjuh`
* **Decrypted Message:** `Hello World we are implemeting Multiplicative Cipher`
* **Original Hash:** `1473110027851352879`
* **Final Hash:** `1473110027851352879`
* **Verification:** Non-alphabetic characters (spaces) were preserved during the transformation. The integrity check confirms that the decrypted message is identical to the original input. to the original input.
---

## 6. Implementation Features
* **Modular Inverse:** Using a brute-force approach ($1 \dots 26$) for maximum reliability in small moduli.
* **Case Sensitivity:** Correctly handles `upper` and `lower` case using ASCII base offsets.
* **Memory Efficiency:** Uses `unsigned long long` to prevent overflow during bit-mixing and large prime multiplications.

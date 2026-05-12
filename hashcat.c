#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

char current_module[50] = "";
char target_hash[256] = "";
char wordlist[512] = "";

/* =========================
   HEX CONVERTER
   ========================= */
void to_hex(unsigned char *hash, int len, char *output) {
    for (int i = 0; i < len; i++)
        sprintf(output + (i * 2), "%02x", hash[i]);
    output[len * 2] = 0;
}

/* =========================
   DICTIONARY MODE
   ========================= */
void dict_crack() {
    printf("[+] Dictionary mode\n");
    printf("[DEBUG] Wordlist: %s\n", wordlist);

    FILE *file = fopen(wordlist, "r");
    if (!file) {
        perror("[-] Cannot open wordlist");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (strcmp(line, target_hash) == 0) {
            printf("[+] FOUND: %s\n", line);
            fclose(file);
            return;
        }
    }

    printf("[-] Not found\n");
    fclose(file);
}

/* =========================
   MD5 MODE
   ========================= */
void md5_crack() {
    printf("[+] MD5 mode\n");
    printf("[DEBUG] Wordlist: %s\n", wordlist);

    FILE *file = fopen(wordlist, "r");
    if (!file) {
        perror("[-] Cannot open wordlist");
        return;
    }

    char line[256];
    unsigned char hash[MD5_DIGEST_LENGTH];
    char hex[33];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        MD5((unsigned char*)line, strlen(line), hash);
        to_hex(hash, MD5_DIGEST_LENGTH, hex);

        if (strcmp(hex, target_hash) == 0) {
            printf("[+] FOUND: %s\n", line);
            fclose(file);
            return;
        }
    }

    printf("[-] Not found\n");
    fclose(file);
}

/* =========================
   SHA256 MODE
   ========================= */
void sha256_crack() {
    printf("[+] SHA256 mode\n");
    printf("[DEBUG] Wordlist: %s\n", wordlist);

    FILE *file = fopen(wordlist, "r");
    if (!file) {
        perror("[-] Cannot open wordlist");
        return;
    }

    char line[256];
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char hex[65];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        SHA256((unsigned char*)line, strlen(line), hash);
        to_hex(hash, SHA256_DIGEST_LENGTH, hex);

        if (strcmp(hex, target_hash) == 0) {
            printf("[+] FOUND: %s\n", line);
            fclose(file);
            return;
        }
    }

    printf("[-] Not found\n");
    fclose(file);
}

/* =========================
   RUNNER
   ========================= */
void run_attack() {

    printf("[+] Module: %s\n", current_module);

    if (strlen(wordlist) == 0) {
        printf("[-] No wordlist set\n");
        return;
    }

    if (strcmp(current_module, "md5") == 0)
        md5_crack();
    else if (strcmp(current_module, "sha256") == 0)
        sha256_crack();
    else
        dict_crack();
}

/* =========================
   MAIN CLI
   ========================= */
int main() {

    char input[256];

    printf("HashFW CLI v1.0\n");

    while (1) {

        printf("hashfw > ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
            break;

        /* HELP */
        else if (strncmp(input, "-h", 2) == 0 || strncmp(input, "--help", 6) == 0) {
            printf("\nCommands:\n");
            printf("  -u <module>         --use <module>        md5 | sha256 | dict\n");
            printf("  -sh <hash>          --hash <hash>         target hash\n");
            printf("  -sw <file>          --wordlist <file>     wordlist path\n");
            printf("  -r                  --run                 start attack\n");
            printf("  exit                                      quit\n\n");
        }

        /* MODULE */
        else if (strncmp(input, "-u ", 3) == 0 || strncmp(input, "--use ", 6) == 0) {
            char *m = strchr(input, ' ');
            while (*m == ' ') m++;
            strncpy(current_module, m, sizeof(current_module)-1);
            printf("[+] Module: %s\n", current_module);
        }

        /* HASH */
        else if (strncmp(input, "-sh ", 4) == 0 || strncmp(input, "--hash ", 7) == 0) {
            char *h = strchr(input, ' ');
            while (*h == ' ') h++;
            strncpy(target_hash, h, sizeof(target_hash)-1);
            printf("[+] Hash set\n");
        }

        /* WORDLIST */
        else if (strncmp(input, "-sw ", 4) == 0 || strncmp(input, "--wordlist", 10) == 0) {
            char *w = strchr(input, ' ');
            while (*w == ' ') w++;
            strncpy(wordlist, w, sizeof(wordlist)-1);
            printf("[+] Wordlist: %s\n", wordlist);
        }

        /* RUN */
        else if (strcmp(input, "-r") == 0 || strcmp(input, "--run") == 0) {
            run_attack();
        }

        else {
            printf("[-] Unknown command (-h for help)\n");
        }
    }

    return 0;
}
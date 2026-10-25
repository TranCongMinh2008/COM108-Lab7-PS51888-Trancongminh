#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h> // Thư viện chứa getch() phục vụ bài ẩn mật khẩu

// --- KHAI BÁO CÁC NGUYÊN MẪU HÀM (FUNCTION PROTOTYPE) ---
void bai1_DemNguyenAmPhuAm();
void bai2_DangNhapHeThong();
void bai3_SapXepChuoi();
void bai4_ChuyenThapPhanSangHexa();

// HÀM CHÍNH (MAIN) - DỰNG KHUNG MENU CHƯƠNG TRÌNH
int main() {
    int chon;

    do {
        printf("\n+---------------------------------------+\n");
        printf("|        MENU CHUONG TRINH LAB 7        |\n");
        printf("+---------------------------------------+\n");
        printf("| 1. Dem nguyen am va phu am cua chuoi |\n");
        printf("| 2. Dang nhap bang Username va Password |\n");
        printf("| 3. Sap xep chuoi theo thu tu chu cai  |\n");
        printf("| 4. Doi so thap phan sang thap luc phan|\n");
        printf("| 5. Thoat chuong trinh                 |\n");
        printf("+---------------------------------------+\n");
        printf(">> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &chon);
        getchar(); // Xóa bộ nhớ đệm sau khi nhập số để tránh trôi lệnh nhập chuỗi ở sau

        switch(chon) {
            case 1:
                printf("\n--- BAN DA CHON CHUC NANG 1 ---\n");
                bai1_DemNguyenAmPhuAm();
                break;
            case 2:
                printf("\n--- BAN DA CHON CHUC NANG 2 ---\n");
                bai2_DangNhapHeThong();
                break;
            case 3:
                printf("\n--- BAN DA CHON CHUC NANG 3 ---\n");
                bai3_SapXepChuoi();
                break;
            case 4:
                printf("\n--- BAN DA CHON CHUC NANG 4 ---\n");
                bai4_ChuyenThapPhanSangHexa();
                break;
            case 5:
                printf("\nCam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("\nChuc nang khong hop le! Vui long chon lai tu 1 den 5.\n");
        }
    } while(chon != 5);

    return 0;
}

// --- CHI TIẾT CÁC HÀM CHỨC NĂNG ---

// BÀI 1: ĐẾM NGUYÊN ÂM VÀ PHỤ ÂM CỦA MỘT CHUỖI
void bai1_DemNguyenAmPhuAm() {
    char chuoi[100];
    int nguyenAm = 0, phuAm = 0;

    printf("Nhap vao mot chuoi: ");
    fgets(chuoi, sizeof(chuoi), stdin);
    
    // Loại bỏ ký tự xuống dòng '\n' do fgets tự động nhận vào nếu có
    chuoi[strcspn(chuoi, "\n")] = '\0';

    // Duyệt qua từng ký tự cho đến khi gặp ký tự kết thúc chuỗi '\0'
    for (int i = 0; chuoi[i] != '\0'; i++) {
        char ch = tolower(chuoi[i]); // Chuyển về chữ thường để dễ so sánh

        // Kiểm tra xem có phải chữ cái không
        if (isalpha(ch)) {
            // Nếu là chữ cái và thuộc các ký tự sau thì là nguyên âm
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                nguyenAm++;
            } else {
                phuAm++; // Ngược lại là phụ âm (khoảng trắng, số, ký tự đặc biệt đã bị loại từ isalpha)
            }
        }
    }

    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n", chuoi, nguyenAm, phuAm);
}

// BÀI 2: ĐĂNG NHẬP BẰNG USERNAME VÀ PASSWORD (ẨN KÝ TỰ MẬT KHẨU)
void bai2_DangNhapHeThong() {
    char user_sys[] = "admin";
    char pass_sys[] = "12345";

    char username[50];
    char password[50];
    int i = 0;
    char ch;

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0'; // Xóa dấu xuống dòng

    printf("Password: ");
    // Vòng lặp đọc từng ký tự bằng getch() để ẩn mật khẩu thành dấu *
    while (1) {
        ch = getch(); // Đọc ký tự từ bàn phím mà không hiển thị ra màn hình

        if (ch == '\r' || ch == '\n') { // Nếu nhấn phím Enter thì dừng nhập
            password[i] = '\0';
            break;
        } else if (ch == '\b') { // Nếu nhấn phím Backspace (Xóa)
            if (i > 0) {
                i--;
                printf("\b \b"); // Xóa ký tự '*' vừa in ra màn hình
            }
        } else {
            if (i < sizeof(password) - 1) {
                password[i] = ch;
                i++;
                printf("*"); // Thay ký tự thật bằng dấu sao
            }
        }
    }
    printf("\n"); // Xuống dòng sau khi kết thúc nhập password

    // Tiến hành so sánh chuỗi bằng hàm strcmp()
    if (strcmp(username, user_sys) == 0 && strcmp(password, pass_sys) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Dang nhap that bai!\n");
    }
}

// BÀI 3: SẮP XẾP CHUỖI THEO THỨ TỰ CHỮ CÁI
void bai3_SapXepChuoi() {
    char s[5][20];
    char temp[20];

    // Nhập 5 chuỗi từ bàn phím
    printf("Nhap vao 5 chuoi bat ky:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        s[i][strcspn(s[i], "\n")] = '\0'; // Xóa dấu xuống dòng
    }

    // Thuật toán Bubble Sort (Sắp xếp nổi bọt) lồng 2 vòng lặp
    for (int i = 0; i < 4; i++) {         // Chạy từ 0 đến n - 2
        for (int j = i + 1; j < 5; j++) { // Chạy từ i + 1 đến n - 1
            // Sử dụng strcmp() để so sánh thứ tự bảng chữ cái ASCII
            if (strcmp(s[i], s[j]) > 0) {
                // Hoán vị chuỗi bằng hàm strcpy() qua biến trung gian temp
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    // Xuất kết quả ra màn hình theo định dạng mẫu
    printf("\nCac chuoi sau khi sap xep:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", s[i]);
    }
}

// BÀI 4: ĐỔI SỐ THẬP PHÂN SANG SỐ THẬP LỤC PHÂN (HEXADECIMAL)
void bai4_ChuyenThapPhanSangHexa() {
    long long n;
    printf("Nhap vao mot so nguyen khong am o he thap phan: ");
    scanf("%lld", &n);
    getchar(); // Xóa bộ đệm

    // Kiểm tra tính hợp lệ của dữ liệu đầu vào (Trường hợp số âm)
    if (n < 0) {
        printf("So nhap vao khong hop le!\n");
        return;
    }

    // Trường hợp đầu vào bằng 0 thì xuất trực tiếp là 0
    if (n == 0) {
        printf("So thap luc phan cua 0 la: 0\n");
        return;
    }

    char hexa_digits[] = "0123456789ABCDEF"; // Chuỗi tra cứu ký tự hexa
    char chuoi_dao[50];                     // Chuỗi lưu tạm thời từ thấp đến cao
    char chuoi_hexa[50];                    // Chuỗi kết quả cuối cùng sau khi đảo ngược
    int idx = 0;
    long long goc_n = n;                    // Lưu lại giá trị ban đầu phục vụ hiển thị kết quả

    // Thực hiện thuật toán chia liên tục cho 16 lấy phần dư
    while (n > 0) {
        int du = n % 16;
        chuoi_dao[idx] = hexa_digits[du];   // Gán ký tự tương ứng vào chuỗi tạm
        idx++;
        n = n / 16;
    }
    chuoi_dao[idx] = '\0';                  // Đóng chuỗi tạm thời

    // Tự viết thuật toán đảo chuỗi dùng vòng lặp và hàm strlen() (Không dùng strrev)
    int do_dai = strlen(chuoi_dao);
    int k = 0;
    for (int i = do_dai - 1; i >= 0; i--) {
        chuoi_hexa[k] = chuoi_dao[i];
        k++;
    }
    chuoi_hexa[k] = '\0';                   // Kết thúc chuỗi kết quả hoàn chỉnh

    // In kết quả theo đúng định dạng mẫu
    printf("So thap luc phan cua %lld la: %s\n", goc_n, chuoi_hexa);
}
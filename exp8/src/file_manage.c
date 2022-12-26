/*
 * file name: file_manage.c
 * author: lihuax
 * version: 1.0
 * description: 
 * 鍋囪鏈?3涓鐢燂紝姣忎釜瀛︾敓鏈変笁闂ㄨ鐨勬垚缁╋紝璁捐绋嬪簭浠庨敭鐩樿緭鍏ユ瘡涓鐢熺殑鐩稿叧鏁版嵁(鍏蜂綋鍖呮嫭瀛﹀彿銆佸鍚嶃€佽鏂囨垚缁┿€佹暟瀛︽垚缁┿€佽嫳璇垚缁╋紝姣忎釜瀛︾敓鐨勫叿浣撴暟鎹唴瀹圭敱璁捐鑰呰嚜瀹?)锛?
 * 骞惰姹傝绠楀嚭姣忎釜瀛︾敓鐨勫钩鍧囨垚缁╁苟杩涜淇濆瓨銆傚瓨鍌ㄥ鐢熸暟鎹殑缁撴瀯妯″瀷鍙互閫夋嫨绾挎€ц〃鎴栬€呭崟鍚戦摼琛紝鏁版嵁缁撴瀯涓粨鏋勫彉閲忕殑缁勬垚鍏冪礌鍜岀被鍨嬬敱璁捐鑰呮牴鎹鐩姹傝嚜宸卞畾涔夈€?
 * 灏嗗凡杈撳叆鐨勫鐢熸暟鎹俊鎭拰璁＄畻鍑虹殑骞冲潎鍒嗘暟鍐欏叆鏂囦欢stud.txt锛屽苟閫氳繃璇诲彇璇ユ枃浠舵樉绀哄埌灞忓箷涓婃潵妫€鏌tud.txt鏂囦欢涓殑瀛︾敓骞冲潎鍒嗚绠楁槸鍚︽纭€?
 */

#include<stdio.h>
#include<stdlib.h>

int main (void)
{
    char ch;
    FILE *fp;
    fp = fopen("./a.txt", "r+");
    if(fp==NULL)
        printf("鏂囨。鎵撳紑澶辫触");
    else
    {
        ch=fgetc(fp);
        putchar(ch);
    }
    //鍐欏叆瀛楃
    if(fputc('A',fp)==-1)
        printf("F");
    else
        printf("T");
    
    fclose(fp);
    return 0;
}
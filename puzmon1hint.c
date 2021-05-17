/*=== puzmon1hint: ゲーム全体の流れの実装 ===*/
/*** インクルード宣言 ***/

#include <stdio.h>

/*** 列挙型宣言 ***/

/*** グローバル定数の宣言 ***/

/*** 構造体型宣言 ***/

/*** プロトタイプ宣言 ***/
int goDungeon(char *player);

int doBattle(char *player, char *monster);

// HINT: goDungeon関数のプロトタイプ宣言
// HINT: doBattle関数のプロトタイプ宣言

/*** 関数宣言 ***/

// (1)ゲーム開始から終了までの流れ
int main(int argc, char **argv) {
  // HINT: もし起動時のこまんどライン引数の数が異常なら{
  // HINT:     エラーメッセージを表示して異常終了
  // HINT: }
  if (argc != 2) {
    printf("エラー: プレイヤー名を指定して起動してください\n");
    return 1;
  }

  printf("*** Puzzle & Monsters ***\n");

  // いざ、ダンジョンへ
  // HINT: ダンジョンに行く関数を呼び出し、勝利数を戻り値で得る
  int wins = goDungeon(argv[1]);
  // 冒険終了後
  // HINT: 勝利数が5なら {
  // HINT:     ゲームクリアの表示をする
  // HINT: } そうでないなら {
  // HINT:     ゲームオーバーの表示をする
  // HINT: }
  if (wins == 5) {
    printf("***GAME CLEARED!***\n");
  } else {
    printf("***GAME OVER***\n");
  }
  // HINT: 倒したモンスター数を表示する
  printf("倒したモンスター数＝%d\n", wins);
  return 0;
}

// (2)ダンジョン開始から終了までの流れ
int goDungeon(/* HINT: プレイヤー名 */char *player) {
  // HINT:「○○はダンジョンに到着した」と表示する
  printf("%sはダンジョンに到着した\n", player);
  // HINT: 勝利数を格納する変数を準備し0にセットする
  int wins = 0;
  // HINT: スライムと戦うバトルを実行する関数を呼び出し、結果を勝利数に足す
  wins += doBattle(player, "スライム");
  // HINT: ゴブリンと戦うバトルを実行する関数を呼び出し、結果を勝利数に足す
  wins += doBattle(player, "ゴブリン");
  // HINT: オオコウモリと戦うバトルを実行する関数を呼び出し、結果を勝利数に足す
  wins += doBattle(player, "オオコウモリ");
  // HINT: ウェアウルフと戦うバトルを実行する関数を呼び出し、結果を勝利数に足す
  wins += doBattle(player, "ウェアウルフ");
  // HINT: ドラゴンと戦うバトルを実行する関数を呼び出し、結果を勝利数に足す
  wins += doBattle(player, "ドラゴン");

  // HINT: 「○○はダンジョンを制覇した！」と表示する
  printf("%sはダンジョンを制覇した！\n", player);
  return wins/* HINT: 勝利数 */;
}

// (3)バトル開始から終了までの流れ
int doBattle(/* HINT: プレイヤー名 */char *player, /* 敵の名前 */char *monster) {
  // HINT: 「××が現れた」と表示する
  printf("%sが現れた！\n", monster);
  // （ダミー戦闘で即勝利確定）

  // HINT: 「××を倒した！」と表示する
  printf("%sを倒した！\n", monster);
  return 1;   // 倒した敵の数（常に1）を返す
}

/*** ユーティリティ関数宣言 ***/

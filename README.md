# BSQがんばろ
一人で考えていたら光明がさしたので、とりあえずこんな感じかなと
ひたすら関数を作って試してください
## ディレクトリ規則
### ディレクトリ構成
* BSQ.c : main関数が入ったファイル
* Makefile : コンパイルは毎回これでやりましょう。早めの準備を忘れずに
* srcs : とりあえずソースコードはここにひたすらぶち込む
* includes : ヘッダーファイルをここにぶち込む
* object : オブジェクトファイルはここにしまっておく？これはなくても大丈夫なら消します。
* .gitignore : とりあえず「.DS_store」と「a.out」はプッシュしないようにしてあります。適宜追加してください。

### 命名規則
* 基本的に使う関数名はnormに則ること
* 関数名、ファイル名共に頭に「ft_」をつけること！忘れずに！！！！！！(これつけないとメインのコンパイルで一緒に入れてもらえません。逆に関数を試しに使いたいだけならft_をつけなければメインのものに影響しないので、わかりにくくならない範囲で好きに作ってください)
* includeするのは「../includes/ft_tools.h」のみにする（unistdとかも入ってます。）

## 作業ルール
### 作業終了時にやること（これをやらずに作業をしたとは言わせない）
* ヘッダーファイル「ft_tools.h」に使用した関数のプロトタイプ宣言を記載する
* Makefileに作業が終わったソースコードのファイル名を忘れずに記載すること
* **作業中断時にpushを忘れずに！** PCの前で操作ができなくなる時間が発生するならすぐpushです。トイレのたびにとは言いませんが、相手がコードをみたいと思った時に見えるようにしてあげましょう！ **思いやり大事！**

## 必要な関数
２が多分一番重いので、進めててわからなければ疑問をslackに投げて他の番号に移っていいです。

### 1.マップデータを読み込む
* ファイルパスからデータを読み込む
* マップの行数をカウントする（これで繰り返し処理の限界値が決まる重要なやつ）
* マップで使われる文字を確認する（多分c07あたりのbaseのイメージで大丈夫）
* マップ自体を配列or構造体にぶち込む（ここのルールは早く決めないと作業に支障あり）

### 2a.大きい四角を探す
* 再帰で描くのがいいかも
* 左上からemptyの場合は四角を大きくしていって、obstacleもしくは行端に当たったら成長を止める
* このプログラムを左上から右に進めて、行端まできたら次の行で同じ繰り返し
* 多分このプログラムが一番しんどい、、、笑
* この自身を繰り返す時に、前の四角と大きさを比べて、新しいやつが大きかったら、３を実行する

### 2b.大きい四角を探す（ひし形の時）
* 左上の起点と右下の終点を規定するのは2aと変わらない
* 四角の書き方が難しくなるので、ルールを整理する必要あり
* 2aよりだいぶてまがかかるので、とりあえずはそのまま放置でもいいかな。余裕があればやりましょう。ひとまず2aで動くことが大前提です。

### 3.描いた四角の大きさを保存しておくプログラム（メモリ操作）
* その時点で一番大きい四角が描けた箇所の「始端、大きさ」の情報を保管しておく
* 2のプログラムの中でこのプログラムを実行して、随時更新する
* 実行前にその前に使ってる保存領域をfreeする
* mallocで領域を確保する（単に配列がリセットされるならなんでもいい）

### 4.過去一大きい四角を確定させて、文字列を書き換える
* 2を繰り返し処理しきったあとに3のメモリに残っている情報を元に文字列の配列を置き換える
* 多分これは簡単

### 5.文字列をひたすら出力する(ft_putmap)
* 書き換えたマップをひたすらに出力する関数
* とりあえず作りました。みておいてください。

## マップメーカーの使い方
1. コマンドラインで、「perl mapmaker.pl $width $line_count $romdom_seed」を入力
1. コマンドライン上にマップが出来上がるので、それをechoなりクリップボードコピーなりでテキストファイルを作成する

width = 1行の文字数
line_count = 行数
rondom_seed = 邪魔オブジェクトの配置（ランダムになるので、適当でいいけど、数字を大きくすると数が増えていきます

そんな感じでとりあえずマップ作って遊んでみてください。

## 課題リスト
### Makefile
* 実行ファイル名の指定がわからん
* オブジェクトファイルにするみたいなところが必要かわからん

### map to file
* 構造体がいい気がする
	struct s_map{
		int		line_count; ←mapの行数
		char	*mark; ←記号のマーク
		char	**map; ←mapの文字列の配列
		int		sq_point_s[2]; ←スタートポイントのxy座標
		int		sq_point_l[2]; ←エンドポイントのxy座標
		int		sq_bool; ←四角形が正方形かひし形かの判断
		int		err; 現時点で持っているエラー番号
		}

* なので、構造体の宣言をヘッダーファイルにつっこみましょう

### エラー処理
* エラー番号を決める。
* main関数でint *err;を定義する。
* エラーが起こりうる関数処理の引数にerrをいれる。
* エラーが起こったらメッセージを吐きつつ、errにエラー番号代入して関数終了しましょう

#pragma once
#include <vcclr.h>
#include <wchar.h>
#include <tchar.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <time.h>
#include <Windows.h>
#include <iostream>
namespace SimplexForm {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			Pbook = xlCreateXMLBook();
			List =  Pbook->addSheet(L"Распределение товаров",0);
			InitializeComponent();
			сохранитьКакToolStripMenuItem->Enabled=false;
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ FileDialog;
	private: System::Windows::Forms::SaveFileDialog^ SaveDialog;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	
      private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::TextBox^  textBox1;

      private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Button^  button1;
			 //Переменные для симплекса
	private: int NumberVariables;
	private: int NumberLimits;
	private: int *Oindex;
	private: int *num;
	//private: Fraction *kolkor;
	private: Fraction *weight;
	private: Fraction *V;		//объем коробки каждого вида товара
	private: Fraction *cost;		//цена одной коробки каждого вида товара
	private: double MassaKonteinera; 
	private: double ObiemKonteinera;
	private: Fraction *ro;		//плотность коробки каждого вида товара
	private: Fraction *ro_c;//873.07582756;						//плотность контейнера
	private: Fraction *delta_ro;
	private: bool check; //проверка на то, что смогли считать таблицу из файла
	private: bool *CheckBox;
	public: Fraction *kolkor;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::ToolStripMenuItem^  сохранитьКакToolStripMenuItem;
	private: Book* Pbook;
	private: Sheet* List;
	private: Sheet* sheet;
	private: int CountKon, FileShift, id, CcountKon, OCountKon;
	private: wchar_t** names;
	private: int offset;
	private: double stoimost;
	private: System::Windows::Forms::ToolStripMenuItem^  помощьToolStripMenuItem;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьКакToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());

this->помощьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SaveDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->файлToolStripMenuItem, 
				this->помощьToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(576, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->открытьToolStripMenuItem, 
				this->сохранитьКакToolStripMenuItem, this->выходToolStripMenuItem});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(45, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// открытьToolStripMenuItem
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			
this->открытьToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->открытьToolStripMenuItem->Text = L"Открыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// сохранитьКакToolStripMenuItem
			// 
			this->сохранитьКакToolStripMenuItem->Name = L"сохранитьКакToolStripMenuItem";
			this->сохранитьКакToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->сохранитьКакToolStripMenuItem->Text = L"Сохранить как";
			this->сохранитьКакToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::сохранитьКакToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// помощьToolStripMenuItem
			// 
			this->помощьToolStripMenuItem->Name = L"помощьToolStripMenuItem";
			this->помощьToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->помощьToolStripMenuItem->Text = L"Помощь";
			this->помощьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::помощьToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(346, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Вид контейнера";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(448, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(119, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Стоимость перевозки";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 41);
			this->label3->Name = L"label3";
                  this->label3->Size = System::Drawing::Size(88, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Вид контейнера";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(106, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(107, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Число контейнеров";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(219, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Общая стоимость";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(31, 66);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(32, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"20FT";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(31, 95);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(32, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"40FT";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(31, 122);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(48, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"40FTHQ";
			this->label8->Visible = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(365, 66);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(51, 17);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->Text = L"20FT";
			
this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(365, 91);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(51, 17);
			this->checkBox2->TabIndex = 10;
			this->checkBox2->Text = L"40FT";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(365, 118);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(67, 17);
			this->checkBox3->TabIndex = 11;
			this->checkBox3->Text = L"40FTHQ";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(450, 63);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(110, 20);
			this->textBox1->TabIndex = 12;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(450, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(110, 20);
			this->textBox2->TabIndex = 13;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(450, 116);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(110, 20);
			this->textBox3->TabIndex = 14;
			this->textBox3->Visible = false;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(31, 239);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 13);
			this->label9->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(349, 168);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(211, 23);
this->button1->TabIndex = 17;
			this->button1->Text = L"Провести расчет";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 

// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(135, 66);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 13);
			this->label10->TabIndex = 18;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(135, 95);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 19;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(135, 122);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 13);
			this->label12->TabIndex = 20;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(242, 66);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 13);
			this->label13->TabIndex = 21;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(242, 95);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 13);
			this->label14->TabIndex = 22;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(242, 122);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(0, 13);
			this->label15->TabIndex = 23;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			
this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(576, 270);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Оптимизация загрузки контейнеров, Мешков Иван, Диплом";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: wchar_t* ConstWchToWch(const wchar_t* str)
				 {
					 int i = 0;
					 while(str[i]!='\0')
					 {
						 i++;
					 }
					 wchar_t* pluha = new wchar_t[i+1];
					 for (int j = 0; j < i; j++)
					 {
						 pluha[j] = str[j];
					 }
					 pluha[i] = '\0';
					 return pluha;
				 }

		private: System::String^ wchar_tToSysString(wchar_t* str)
				 {
					 System::String^ sysstr = gcnew System::String(str);
					 return sysstr;
		 }
		private: System::String^ ConstWchar_tToSysString(const wchar_t* str)
				 {
					 std::wostringstream streamVal;
					 streamVal << str;
	
					 System::String^ sysstr = gcnew System::String(streamVal.str().c_str());
					 return sysstr;
				 }

		private: const wchar_t* WchToConstWch(wchar_t* str)
				 {
					 System::String^ numstr = wchar_tToSysString(str);
					 wchar_t* pluha = new wchar_t[numstr->Length+2];
					 for(int i = 0; i < numstr->Length; i++)
					 {
						 pluha[i] = cli::safe_cast<wchar_t>(numstr->ToCharArray()->GetValue(i));
					 }
					 pluha[numstr->Length+1] = '\0';
					 return pluha;
				 }

		private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->NumberLimits = 2;
			 int pos = 1, newpos;
				 System::String^ str;
			 Book* book = xlCreateXMLBook(); check = false;
			 if(book)//Проверка что книгу мы смогли создать
			 {//Convert::ToChar(FileDialog->FileName)
				 FileDialog->Filter = "Файлы заказов товаров|*.xlsx";
				 if(FileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					{

					
						if(book->load(StringToWchar_t(FileDialog->FileName)))
				 {
					 sheet = book->getSheet(0);
					 if(sheet)
					 {	check = true;
						 label9->Text = FileDialog->FileName;
						 NumberVariables = sheet->lastRow() - 1;
						 //debug->Text = IntegerToSystemString(NumberVariables);
						 IntegerToSystemString(NumberVariables);
						 names = new wchar_t*[NumberVariables];
						 kolkor = new Fraction[NumberVariables];
 weight = new Fraction[NumberVariables];
						 V = new Fraction[NumberVariables];
						 cost = new Fraction[NumberVariables];
						 ro = new Fraction[NumberVariables];
						 Oindex = new int[NumberVariables];
						 num = new int[NumberVariables];
//						 MessageBox::Show("перед забиванием массивов");
						 while(pos != sheet->lastRow())
						 {
							 book->load(StringToWchar_t(FileDialog->FileName));
							 sheet = book->getSheet(0);
							 if(pos < sheet->lastRow() - 10)
								 newpos = pos + 10;
							 else
								 newpos = sheet->lastRow();
							 for(int i = pos; i < newpos; i++)				//Начало считывания нашего файла! <---------------------------
							 {
								 Oindex[i-1] = i-1;
								 num[i-1] = i;
								 names[i-1] = ConstWchToWch(sheet->readStr(i, 0));
								 kolkor[i-1] = Fraction::Fraction(sheet->readNum(i, 1)); 
								 weight[i-1] = Fraction::Fraction(sheet->readNum(i, 4)); 
								 V[i-1] = Fraction::Fraction(sheet->readNum(i, 6));	   
								 cost[i-1] = Fraction::Fraction(sheet->readNum(i, 9));
								 ro[i-1]  = weight[i-1]/V[i-1];
							 }
							 pos = newpos;
							 book = xlCreateXMLBook();
						 }
					 }
					 else MessageBox::Show("Ошибка загрузки таблицы, не удалось получить таблицу!"); 
				 }
				 else MessageBox::Show("Ошибка загрузки файла, не удалось считать файл!"); 
					}
				}
			 else MessageBox::Show("Ошибка создания книги, не удалось считать файл!");// * /
		 }


		private: const wchar_t* IntToWchar_t(int num)
				 {
					 System::String^ numstr = num.ToString();
					 System::String^ numstr2 = L" контейнер";
					 wchar_t* pluha = new wchar_t[numstr->Length+11];
					 for(int i = 0; i < numstr->Length; i++)
					 {
					 pluha[i] = cli::safe_cast<wchar_t>(numstr->ToCharArray()->GetValue(i));
					 }
					 for(int i = numstr->Length; i < numstr->Length + 10; i++)
					 {
						 pluha[i] = cli::safe_cast<wchar_t>(numstr2->ToCharArray()->GetValue(i-numstr->Length));
					 }
					 pluha[numstr->Length+10] = '\0';
					 return pluha;
				 }//*/
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					 label10->Text=""; label11->Text=""; label12->Text=""; label13->Text=""; label14->Text=""; label15->Text="";

			 double cost20 = 0, cost40 = 0, cost40HQ = 0;
			 id = -1;
			 CountKon = 0; OCountKon = 0;
			 CheckBox = new bool[3]; CheckBox[0] = false; CheckBox[1] = false; CheckBox[2] = false;
			 //открытьToolStripMenuItem_Click(sender, e);
			 Fraction *NumberBox = new Fraction[NumberVariables];
			 //check = true; //чтобы каждый раз поновой не открывать файл
			 FileShift = 0;
			 if(!check) 
				 MessageBox::Show(L"Необходимо сначало открыть файл с товарами!");
			 else {
				 if(checkBox1->Checked::get())
				 { FileShift += List->lastRow()+ 2;
					 List->writeStr(FileShift,0,L"20FT");
					 for(int r = 1; r < NumberVariables+1; r++)
					 {
						 FileShift++;
						//List->writeStr(FileShift,0,sheet->readStr(r,0,0));
						 List->writeStr(FileShift,0,WchToConstWch(names[r-1]));
					 }
					 if(textBox1->Text == "")
						MessageBox::Show(L"Не заполнено поле стоимости для 20FT!");
					 else
					 {
						 if(Double::TryParse(textBox1->Text, cost20))
							CheckBox[0] = true;
						 else MessageBox::Show("Некорректный ввод в поле стоимости 20FT!");
					 }
				 }

				 if(checkBox2->Checked::get())
				 {	FileShift+=2;
					 List->writeStr(FileShift,0,L"40FT");
					 for(int r = 1; r < NumberVariables+1; r++)
					 {
	 FileShift++;
						 //List->writeStr(FileShift,0,sheet->readStr(r,0,0));
						 List->writeStr(FileShift,0,WchToConstWch(names[r-1]));
					 }
					 if(textBox2->Text == "")
						MessageBox::Show(L"Не заполнено поле стоимости для 40FT!");
					 else
					 {
						if(Double::TryParse(textBox2->Text, cost40))
						 	CheckBox[1] = true;
						else MessageBox::Show("Некорректный ввод в поле стоимости 40FT!");
					 }
				 }
				 if(checkBox3->Checked::get())
				 {
					 FileShift+=2;
					 List->writeStr(FileShift,0,L"40FTHQ");
					 for(int r = 1; r < NumberVariables+1; r++)
					 {
						 FileShift++;
						 //List->writeStr(FileShift,0,sheet->readStr(r,0,0));
						 List->writeStr(FileShift,0,WchToConstWch(names[r-1]));
					 }
					 if(textBox3->Text == "")
						MessageBox::Show(L"Не заполнено поле стоимости для 40FTHQ!");
					 else
					 {
						 if(Double::TryParse(textBox3->Text, cost40HQ))
						 	CheckBox[2] = true;
						 else MessageBox::Show("Некорректный ввод в поле стоимости 40FTHQ!");
					 }
				  }
				 FileShift = 0;
				 offset = 2;
				 for(int i = 0; i < 3; i++)
				 {
					 if(CheckBox[i])
					 {
						 CountKon = 0; OCountKon = 0;
						 for (int j = 0; j < NumberVariables; j++)
						 {
							 NumberBox[j] = kolkor[j];
						 }
						 if(i == 0) 
						 {
							 stoimost = cost20;
							 MassaKonteinera = 28200;
							 ObiemKonteinera = 32.3;
						 }
				
	 else if(i == 1)
						 {
							 stoimost = cost40;
							 MassaKonteinera = 26600;
							 ObiemKonteinera =  67.5;
						 }
						 else if(i == 2)
						 {
							 stoimost = cost40HQ;
							 MassaKonteinera = 26580;
							 ObiemKonteinera = 73.5;
						 }
						 System::String^ t;


						 while(!CheckBoxNull(NumberBox, NumberVariables))
						 {
							t = "";
							t+= "Колличество коробок до симплекса:\n";
							for (int j = 0; j < NumberVariables; j++)
							{
								 t+= StdStringToSystemString(NumberBox[j].toString()) + "___";
							}
							//MessageBox::Show(t);
							CountKon++;
							//MessageBox::Show(IntegerToSystemString(CountKon));
							int start_time = GetTickCount();
							simplex(MassaKonteinera, ObiemKonteinera, &NumberBox);
							int finish_time = GetTickCount();
							//MessageBox::Show("Симплекс метод работал:" + IntegerToSystemString(finish_time - start_time));
							List->writeStr(1,OCountKon+1, /*CountKon.ToChar()*/ IntToWchar_t(CountKon)/*(const char*)CountKon*/);
							List->writeStr(1,OCountKon+2, /*CountKon.ToChar()*/ L"Себестоимость перевозки, руб."/*(const char*)CountKon*/);
							OCountKon +=2;
							t = "";
							t+= "Колличество коробок после симплекса:\n";
							for (int j = 0; j < NumberVariables; j++)
							{
								t+= StdStringToSystemString(NumberBox[j].toString()) + "___";
							}
							//MessageBox::Show(t);
						 }FileShift+=NumberVariables + 2;
						 label13->ForeColor = System::Drawing::Color::Black;
						 label14->ForeColor = System::Drawing::Color::Black;
	 label15->ForeColor = System::Drawing::Color::Black;
						 stoimost = 0;
						 if(i == 0) 
						 {	 if(cost20*CountKon!=0) { CcountKon = CountKon; offset = 2; id = 0; stoimost = cost20*CountKon; }
							 label10->Text = IntegerToSystemString(CountKon);
							 label13->Text = DoubleToSystemString(cost20*CountKon);
			//this->label9->ForeColor = System::Drawing::Color::Red;
						 }
						 else if(i == 1)
						 {  if((stoimost == 0 || stoimost > cost40*CountKon) && cost40*CountKon != 0)
							{
								offset += NumberVariables + 2;
								CcountKon = CountKon;
								id = 1; stoimost = cost40*CountKon;
							}
							label11->Text = IntegerToSystemString(CountKon);
							label14->Text = DoubleToSystemString(cost40*CountKon);
						 }
						 else if(i == 2)
						 {
							 if((stoimost == 0 || stoimost > cost40HQ*CountKon) && cost40HQ*CountKon != 0)
							 {
								 CcountKon = CountKon;
								 offset += NumberVariables + 2;
								 id = 2; stoimost = cost40HQ*CountKon;
							 }
							label12->Text = IntegerToSystemString(CountKon);
							label15->Text = DoubleToSystemString(cost40HQ*CountKon);
						 }
						 if(id == 0) { 	сохранитьКакToolStripMenuItem->Enabled = true; label13->ForeColor = System::Drawing::Color::Red; }
						 else if (id == 1) { 	сохранитьКакToolStripMenuItem->Enabled = true; label14->ForeColor = System::Drawing::Color::Red; }
					 else if (id == 2) { 	сохранитьКакToolStripMenuItem->Enabled = true; label15->ForeColor = System::Drawing::Color::Red; }

					 }
					 //else MessageBox::Show("false");
				 }
			 } //*/
		 }

/*----------------------------- Функции для симплекса ------------------------------------*/

public: System::String^ StdStringToSystemString(std::string str)
			 {
				 System::String^ SystemString = gcnew System::String(str.c_str());
				 return SystemString;
			 }

private: System::String^ IntegerToSystemString(int num)
		 {

			 std::ostringstream ost;
			 ost << num;
			 System::String^ SystString = gcnew System::String(ost.str().c_str());
			 return SystString;
// 			 System::String^ SystString = gcnew System::String(num.ToString());
// 			 return SystString;
		 }
private: System::String^ DoubleToSystemString(double num)
		 {
			// MessageBox::Show("Вызвалась функция дабл ту стринг");
			 //std::ostringstream testk;
			 //testk << num;
			 //System::String^ SystemString = gcnew System::String(ost.str().c_str());
			 //return SystemString;//*/
			 System::String^ SystString = gcnew System::String(num.ToString());
			 return SystString;
		 }

private: System::Void OutputMatrix(Fraction **A, int CountRow, int CountCol){
				 System::String^ out;
				 for(int i = 0; i < CountRow; i++)
				 {
					 for (int j = 0; j < CountCol; j++)
					 {
						 out += StdStringToSystemString(A[i][j].toString()) + " ";
					 }
					 out += "\n";
				 }
				 MessageBox::Show(out);
			 } 
private: Fraction absolut(Fraction num)
					  {
						  if(num < 0)
							  num = num*(-1);
						  return num;
					  }
private: int kreko(Fraction **matrixLIM, int CountRow, int CountCol, Fraction *Borigin, int nVedStolb, int *krekoTETTA)
		 {
			 Fraction CompareElem;
			 bool flagFirstUse = true;
			 int nVedStrok = 0;
	
	 Fraction **A = new Fraction*[CountRow];
			 Fraction *B = new Fraction[CountRow];
			 for(int i = 0; i < CountRow; i++)
			 {
				 B[i] = Borigin[i];
				 A[i] = new Fraction[CountCol];
				 for(int j = 0; j < CountCol; j++)
				 {
					 A[i][j] = matrixLIM[i][j];
				 }

			 }
			 for(int i = 0; i < CountRow; i++)
			 {
				 if(matrixLIM[i][nVedStolb] == 0)
					krekoTETTA[i] = 0;
				 if(krekoTETTA[i] != 0)
				 {
					 for(int j = 0; j < CountCol; j++)
					 {
						 A[i][j] = A[i][j]/matrixLIM[i][nVedStolb];
					 }
					 B[i] = B[i]/matrixLIM[i][nVedStolb];
				 }
			 }

			 int indexMin = 0;
			 bool flagL = false;
				 for(int j = 0; j < CountCol; j++)
				 {
					 CompareElem = A[0][j];
					 for(int i = 0; i < CountRow; i++)
					 {
						 if(krekoTETTA[i] != 0)
						 {
							 if(CompareElem != A[i][j])
							 {
								 for(int e = 0; e < CountRow; e++)
								 {	if(CompareElem > A[e][j] &&  A[e][j] != 0 && krekoTETTA[e] != 0)
								 {
									 CompareElem = A[e][j];
									 indexMin = e;
								 }
								 }
								 nVedStrok = indexMin;
								 flagL = true;
							 }
						 }
					 }
					 if(flagL == true) break;
				 }
			 return nVedStrok;
		 }

private: bool CountEval(Fraction** matrixLIM, Fraction* MassBass, Fraction *ocenki, int num_l, int num_v, Fraction *StoimostVCel)
{
			 System::String^ str;
			 Fraction lol;
			 bool flagOk = true;
			 int kol = 0;
			 for(int j = 0; j <  num_l + 2*num_v; j++)
			 {
				 ocenki[j] = 0;
				 kol = 0;
				 while (kol < num_l + num_v)
				 { 
					 ocenki[j] += matrixLIM[kol][j]*MassBass[kol+num_v];
					 kol++;
				 }
				 ocenki[j] = ocenki[j] - StoimostVCel[j]; //расчет строки оценок!!!!!!!!!!!!!!!!!!!!!!!!!
				 str += StdStringToSystemString(ocenki[j].toString()) + " | ";
				 if(ocenki[j] < 0)
					 flagOk = false;/**/
			 }
			 //MessageBox::Show("Оценки: " + str);
			 return flagOk;
		 }

private: void FindVedElem(Fraction* ocenki, Fraction**matrixLIM, Fraction* B, int num_l,int num_v, Fraction* tetta, int *nVedStolb, int *nVedStrok)
		 {
			 Fraction MaxAbsOcenka(-1);
			 for (int i = 0; i < num_l + 2*num_v; i++)
			 {
				 if(ocenki[i] < 0)
				 {
					 if(MaxAbsOcenka < absolut(ocenki[i])/*ocenki[i].absolut(ocenki[i])*/)
					 {
						 MaxAbsOcenka = absolut(ocenki[i]);
						 *nVedStolb = i;
					 }
				 }
			 }
			 for(int i = 0; i < num_l + num_v; i++)
			 {
				 tetta[i] = Fraction::Fraction(-1);
				 if((matrixLIM[i][*nVedStolb] > 0 && B[i] >= 0 )||(matrixLIM[i][*nVedStolb] < 0 && B[i] <= 0 ))
				 {
					 tetta[i] = B[i]/matrixLIM[i][*nVedStolb];
				 }
			 }
			 /*---------------------------------------------------------------------------------------*/
			 Fraction mintetta;
			 for(int i = 0; i < num_l + num_v; i++)
			 {
				 if(tetta[i] >= 0) // >= не убирать!
				 {
				 
mintetta = tetta[i];
					 *nVedStrok = i;
					 break;
				 }
			 }
			 for(int i = 0; i < num_l + num_v; i++)
			 {
				 if(tetta[i] >= 0)// >= не убирать!
				 {
					 if(mintetta > tetta[i])
					 {
						 mintetta = tetta[i];
						 *nVedStrok = i;
					 }
				 }
			 }
			 //---------------------------------------------------------------------------------------*/
			 int countTETTA = 0;
			 int *krekoTETTA = new int[num_l + num_v];
			 for(int i = 0; i < num_l + num_v; i++)
			 {
				 krekoTETTA[i] = 0;
				 if(mintetta == tetta[i])
				 {
					 countTETTA++;
					 krekoTETTA[i] = 1;
				 }

			 }
			 if(countTETTA > 1)
			 {
				 *nVedStrok = kreko(matrixLIM, num_l + num_v, num_l + 2*num_v, B, *nVedStolb, krekoTETTA);
				 countTETTA = 0;
			 }
		 }

private: void Gomory(Fraction ***matrixLIM, Fraction **B, int **MassBassIndex, Fraction **MassBass, Fraction **StoimostVCel, int *num_l, int *num_v)
		 {
			 MessageBox::Show("Гомори 1");
			 System::String^ str;
 			 //str += "\nМассив индексов базисных переменных: "; for(int i = 0; i < (*num_l)-1 + 2*(*num_v); i++) str += StdStringToSystemString((*MassBass)[i].toString()) + "  "; str += "\n"; MessageBox::Show(str);
			 int kol, nVedStolb;
			 Fraction MaxFractPart(-1);
			 int indexMaxFractPart = -1;
			 for(int i = (*num_v); i < *num_l + 2*(*num_v); i++)
			 {
					 if(MaxFractPart < (*B)[i - (*num_v)].FractPart())
					 {
						 MaxFractPart = (*B)[i - (*num_v)].FractPart();
						 indexMaxFractPart = i - (*num_v);
					 }
			
 }
			 str += "Макс дробная часть " + StdStringToSystemString(MaxFractPart.toString()) + " у элемента " + StdStringToSystemString((*B)[indexMaxFractPart].toString()) + " с индексом " + IntegerToSystemString(indexMaxFractPart) + "\n";
			 str += "Составляем новое ограничение:\n";
			 *num_l = *num_l + 1; //наращиваем новое ограничение
			 Fraction *q = new Fraction[(*num_l) + 2*(*num_v)];
			 for(int j = 0; j < (*num_l)-1 + 2*(*num_v); j++)
			 {
				 q[j] = Fraction::Fraction(0);
				 if((*matrixLIM)[indexMaxFractPart][j].FractPart().getNumerator() != 0)
				 {
					 q[j] = (*matrixLIM)[indexMaxFractPart][j].FractPart()*Fraction::Fraction(-1);
					 			str += " (" + StdStringToSystemString(q[j].toString()) + ")*X" + IntegerToSystemString(j+1) + " ";
				 }
			 }
			 q[(*num_l) + 2*(*num_v)-1] = Fraction::Fraction(1);
			 str += "\nДобавляем дополнительное ограничение в матрицу:\n";
 			 //MessageBox::Show(str);
			 Fraction **a = new Fraction*[(*num_l) + (*num_v)];
			 Fraction *BGomory = new Fraction[(*num_l) + (*num_v)];
			 for(int i = 0; i < (*num_l) + (*num_v); i++)
			 {
				 if(i < (*num_l)-1 + (*num_v)) BGomory[i] = (*B)[i];
				 a[i] = new Fraction[(*num_l) + 2*(*num_v)];
				 for(int j = 0; j < (*num_l) + 2*(*num_v); j++)
				 {
					 a[i][j] = 0;
					 if(i < (*num_l)-1 + (*num_v) && j < (*num_l) - 1 + 2*(*num_v))
						 a[i][j] = (*matrixLIM)[i][j];
					 if(i ==  (*num_l) + (*num_v) -1)
						 a[i][j] = q[j];
				 }
			 }
			 //OutputMatrix(a, (*num_l) + (*num_v), (*num_l) + 2*(*num_v));
			 str = "B =";
			 BGomory[(*num_l) + (*num_v) - 1] = (*B)[indexMaxFractPart].FractPart()*Fraction::Fraction(-1);
			 for(int i = 0; i < (*num_l) + (*num_v); i++) str+= StdStringToSystemString(BGomory[i].toString()) + "  ";


			 bool flagB = false; 
			 Fraction *tettaGomory = new Fraction[(*num_l) + (*num_v*2)];
			 Fraction *ocenkiGomory = new Fraction[(*num_l) + (*num_v*2)];
			 Fraction *MassBassGomory = new Fraction[(*num_l) + (*num_v*2)];
			 int *MassBassIndexGomory = new int[(*num_l) + (*num_v*2)];
			 Fraction *StoimostVcelGomory = new Fraction[(*num_l) + (*num_v*2)];
			 while (!flagB)
{
				 flagB = true;
				 Fraction MinElem = Fraction::Fraction(1);
				 int nVedStrok = 0;
 				 str += "\nМассив индексов базисных переменных: "; for(int i = 0; i < (*num_l)-1 + 2*(*num_v); i++) str += StdStringToSystemString((*MassBass)[i].toString()) + "  "; str += "\n";
				 for(int i = 0; i < (*num_l) + (*num_v); i++)
				 {
					 if(MinElem > BGomory[i] && BGomory[i] < 0 && (*MassBassIndex)[i+(*num_v)] < (*num_v)) //возможно 3 условие лишнее
					 {
						 //flagB = false;
							 //MessageBox::Show(StdStringToSystemString(MinElem.toString()) + " > " + StdStringToSystemString(BGomory[i].toString()) + "\n");
							 MinElem = BGomory[i];
							 nVedStrok = i;
					 }
				 }

 				 str += "Наибольший по модулю среди отрицательных B: " + StdStringToSystemString(MinElem.toString()) + "\n";
 				 //MessageBox::Show(str);
				 for(int i = 0; i <  (*num_l)-1 + 2*(*num_v); i++)
				 {
					 MassBassIndexGomory[i] = (*MassBassIndex)[i];
					 MassBassGomory[i] = (*MassBass)[i];
					 StoimostVcelGomory[i] = (*StoimostVCel)[i];
				 }
				 MassBassGomory[(*num_l)-1 + 2*(*num_v)] = 0;
				 MassBassIndexGomory[(*num_l-1) + 2*(*num_v)] = -1;
				 StoimostVcelGomory[(*num_l)-1 + 2*(*num_v)] = 0;
				 Fraction dubl;
				 for(int j = 0; j <  (*num_l) + 2*(*num_v); j++)
				 {
					 tettaGomory[j] = Fraction::Fraction(-1);
					 ocenkiGomory[j] = Fraction::Fraction(0);
					 kol = 0;
					 while (kol < (*num_l) + (*num_v))
					 {	
						 ocenkiGomory[j] = ocenkiGomory[j] + a[kol][j]*MassBassGomory[kol+(*num_v)];
						 kol++;
					 }
					 ocenkiGomory[j] = ocenkiGomory[j] - StoimostVcelGomory[j]; //расчет строки оценок!!!!!!!!!!!!!!!!!!!!!!!!!
					 if(ocenkiGomory[j] > 0) 
					 {
						 ocenkiGomory[j] = ocenkiGomory[j]*(-1);
					 }
				 }
				 for(int j = 0; j < (*num_l) + 2*(*num_v); j++)
				 {
					 if(a[nVedStrok][j].getNumerator() != 0)
					 {
						 tettaGomory[j] = (ocenkiGomory[j])/(a[nVedStrok][j]);
	 }
				 }
				 for(int i = 0; i < (*num_l) + 2*(*num_v); i++)
				 {if(tettaGomory[i] > 0){MinElem = tettaGomory[i]; nVedStolb = i; break;}}
				 for(int i = 0; i < (*num_l) + 2*(*num_v); i++)
				 {
					 if(tettaGomory[i] > 0)
					 {
						 if(MinElem >= tettaGomory[i]) //>= не убирать!
						 {
							 MinElem = tettaGomory[i];
							 
							 nVedStolb = i;
						 }

					 }
				 }
				 
				 Fraction VedElement = a[nVedStrok][nVedStolb];
				 
				 for(int j = 0; j < (*num_l) + 2*(*num_v); j++)
				 {
					 a[nVedStrok][j] = a[nVedStrok][j]/VedElement;
				 }
				 BGomory[nVedStrok] = BGomory[nVedStrok]/VedElement;
				 Fraction koefficient;
				 for(int i = 0; i < (*num_l) + (*num_v); i++)
				 {
					 koefficient = a[i][nVedStolb];
					 if(i != nVedStrok)
					 {		
						 for(int j = 0; j < (*num_l) + 2*(*num_v); j++)
						 {
							 a[i][j] = a[i][j]  - (a[nVedStrok][j]*koefficient);
						 }
						 BGomory[i] = BGomory[i] - BGomory[nVedStrok]*koefficient;
					 }
				 }
				 for(int i = 0; i < (*num_l) + (*num_v); i++)
				 {
					 if(MinElem > BGomory[i] && BGomory[i] < 0 && MassBassIndexGomory[i+(*num_v)] < (*num_v)) //возможно 3 условие лишнее
					 {
	
	 flagB = false;
					 }
				 }
			 }
			 
			 (*matrixLIM) = a;
			 (*B) = BGomory;
			 (*StoimostVCel) = StoimostVcelGomory;
			 (*MassBass) = MassBassGomory;
			 (*MassBassIndex) = MassBassIndexGomory;			 
		 }

		 private: void ConversionMatrix(Fraction **matrixLIM, Fraction *B, int num_l, int num_v, int nVedStrok, int nVedStolb, Fraction VedElement)
				  {
					  for(int j = 0; j < num_l+ 2*num_v; j++)
					  {
						  matrixLIM[nVedStrok][j] = matrixLIM[nVedStrok][j]/VedElement;
					  }
					  B[nVedStrok] = B[nVedStrok]/VedElement;
					  Fraction koefficient;
					  for(int i = 0; i < num_l + num_v; i++)
					  {
						  koefficient = matrixLIM[i][nVedStolb];
						  if(i != nVedStrok)
						  {		
							  for(int j = 0; j < num_l + 2*num_v; j++)
							  {
								  matrixLIM[i][j] = matrixLIM[i][j]  - (matrixLIM[nVedStrok][j]*koefficient);
							  }
							  B[i] = B[i] - B[nVedStrok]*koefficient;
						  }
					  }
				  }

// Основная функция симплес метода 
public: void simplex(double MassaKonteinera,double ObiemKonteinera, Fraction **NumberBox)
		 {
			 
			 System::String^ str = "";
			 Fraction tempElem = 0;
			 int tempI = 0, maxElemINDEX = 0, tempElemIndex = 0;
			 int num_v = NumberVariables;
			 int num_l = 2;
			 double *Nfunc = new double[num_v];
			 Fraction *func = new Fraction[num_v];
			 
Fraction *ocenki = new Fraction[num_l + 2*num_v];		//Оценки дельта житые
			 int *index = new int[num_v];
			 bool flag = false;
			 bool flagGomory = false;
			 //Fraction ro_c = Fraction::Fraction(Fraction::Fraction(MassaKonteinera)/Fraction::Fraction(ObiemKonteinera));
			 Fraction ro_c = Fraction::Fraction(MassaKonteinera/ObiemKonteinera);
			 delta_ro = new Fraction[NumberVariables];
			 ro_c.reduceFraction();
			 for(int i = 0; i < num_v; i++)				//Начало считывания нашего файла! <---------------------------
			 {
				 index[i] = 0;
				 index[i] = Oindex[i];
				 	if((ro[i] - ro_c) < 0)                      //берем модуль разности плотности коробки и плотности контейнера
					{
						delta_ro[i] = (ro[i] - ro_c)*(-1);    
					}
					else 
					{
						delta_ro[i] = (ro[i] - ro_c);
					}
			 }

			 Fraction maxElem = Fraction::Fraction(-1);
			 for(int j = 0; j < num_v; j++)
			 { //Начало сортировки разницы между плотностью коробки и плотностью контейнера
				maxElem = -1;
				for(int i = j; i < num_v; i++)
				{
					if(maxElem < delta_ro[i])
					{
						maxElemINDEX = index[i];
						maxElem = delta_ro[i];
						tempI = i;
					}
				}
				tempElem = delta_ro[j];
				delta_ro[j] = maxElem;
				delta_ro[tempI] = tempElem;
				tempElemIndex = index[j];
				index[j] = maxElemINDEX;
				index[tempI] = tempElemIndex;
				tempElemIndex = 0;
				tempElem = 0;
			} //Конец сортировки разницы между плотностью коробки и плотностью контейнера
			Nfunc[0] = 1; //Вычисление стоимости товара в соответствии с отсортированными дельты
			for(int i = 1; i < num_v; i++)
			{
				if(delta_ro[i] != delta_ro[i-1])
				{
					Nfunc[i] = Nfunc[i-1] + 1;
	}
				else Nfunc[i] = Nfunc[i-1];
			}
			for(int i = 0; i < num_v; i++)
			{
				func[index[i]] = Fraction::Fraction(Nfunc[i]);
			}       //Окончание вычисления стоимости товара в соответствии с отсортированными дельты
			//---------------------------------------------------------------------------------
			Fraction **matrixLIM = new Fraction*[num_l + num_v];
			for(int i = 0; i < num_l + num_v; i++) //формирование матрицы в симплекс - таблице
			{
				matrixLIM[i] = new Fraction[num_l + 2*num_v]; 
				for(int j = 0; j < num_l + 2*num_v; j++)
				{
					matrixLIM[i][j] = 0;
					if(i ==  num_l+j)
						matrixLIM[i][j] = 1;
				}		
				for(int j =0 ; j < num_v; j++)
				{
					if(i == 0)
						matrixLIM[i][j] = weight[j];
					if(i == 1)
						matrixLIM[i][j] = V[j];
				}
				for(int j = num_v; j < num_l/*колличество ограничений(масса и объем)*/ + 2*num_v; j++)
				{
					if(j-num_v == i)
						matrixLIM[i][j] = 1;
				}	
			}
			//---------------------------------------------------------------------------------
			Fraction *StoimostVCel = new Fraction[num_l + 2*num_v]; //массив коэффициентов в целевой функции; func - массив коэффициентов при свободных переменных
			Fraction *MassBass = new Fraction[num_l + 2*num_v];
			int *MassBassIndex = new int[num_l + 2*num_v];
// 			str = "funci ";	for(int i = 0; i < num_l + 2*num_v; i++) { str += StdStringToSystemString(func[i].toString()) + "   "; } MessageBox::Show(str);
			for(int i = 0; i < num_l + 2*num_v; i++) {
				if(i < num_v)
				{
					StoimostVCel[i] = func[i];
					MassBass[i] = func[i];
				}
				else
				{
					StoimostVCel[i] = 0;
					MassBass[i] = 0;
				}
				MassBassIndex[i] = -1;
			}
			
int kol= 0;
			Fraction TotalCost = Fraction::Fraction(0);
			Fraction* B = new Fraction[num_l+num_v];
			B[0] = MassaKonteinera;
			B[1] = ObiemKonteinera;
			for(int i = 2; i < num_l + num_v; i++)
			{
				B[i] = (*NumberBox)[i-2];
			}
			Fraction cnum;
/////////////////////////////////////Итерации симплекс метода
 			while(flag != true) // Итерации симлекс-метода, пока не найдено решение
			{
				flag = true;

				if(CountEval(matrixLIM, MassBass, ocenki, num_l, num_v, StoimostVCel) == true) //OK
				{  
					while(!flagGomory)
					{
						flagGomory = true;
						for(int i = 0; i < num_l + 2*num_v; i++)
						{
							if(MassBassIndex[i] >= 0)
							{
								if(B[i - num_v].getDenominator() != 1)
								{
									flagGomory = false;
									//if(B[i -num_v].getNumerator() == 0)
									//	flagGomory = true;
								}					
								//MessageBox::Show(StdStringToSystemString((*NumberBox)[i].toString()) + "looool");//(*kolkor)[i] - B[i - num_v];
								//MessageBox::Show("X"+IntegerToSystemString(MassBassIndex[i]+1)+ " = "+ StdStringToSystemString(B[i - num_v].toString()));
							}
						}	
						if(!flagGomory)
						{
 							//str = "Массив индексов базисных переменных до Гомори:"; for(int n = 0; n < num_l+2*num_v; n++) str += StdStringToSystemString(MassBass[n].toString()) + "  "; MessageBox::Show(str);
							//Gomory(&matrixLIM, &B, &MassBassIndex, &MassBass, &StoimostVCel, &num_l, &num_v);	
							for(int i = 0; i < num_l + 2*num_v; i++)
							{
								B[i] = Fraction::Fraction((int)(B[i].getNumerator()/B[i].getDenominator()));
							}
							//OutputMatrix(matrixLIM, num_l+num_v, num_l + 2*num_v);
						

	//------------------------------------------------------------------------------
						}//*/
						else
						{ //запись в эксель контейнеров и себестоимостей
							for(int i = 0; i < num_l + 2*num_v; i++)
							{
								if(MassBassIndex[i] >= 0 && MassBassIndex[i] < num_v)
								{
									(*NumberBox)[MassBassIndex[i]] =   (*NumberBox)[MassBassIndex[i]] - B[i - num_v];
									//List->writeNum(MassBassIndex[i]+FileShift + 3,CountKon, B[i-num_v].getNumerator());
									List->writeNum(MassBassIndex[i]+FileShift + 3,OCountKon+1, B[i-num_v].getNumerator());
										TotalCost += B[i-num_v]*cost[MassBassIndex[i]];
									//List->writeNum()
								}
							}
							for(int i = 0; i < num_l + 2*num_v; i++)
							{
								if(MassBassIndex[i] >= 0 && MassBassIndex[i] < num_v)
								{
									cnum = (B[i-num_v]*cost[MassBassIndex[i]]*Fraction::Fraction(stoimost))/TotalCost;
									List->writeNum(MassBassIndex[i]+FileShift + 3,OCountKon+2, cnum.getNumerator()/cnum.getDenominator()/*cnum.getNumerator()/cnum.getDenominator()*/);
								}
							}
							
						}
					}			 
				}
				else 
				{	
					str = "План неоптимален, так как есть отрицательные оценки!\nОценки: "; for(int i = 0; i < num_l + 2*num_v; i++) { str += StdStringToSystemString(ocenki[i].toString()) + "   "; }
					flag = false;
					int nVedStolb = 0;
					int nVedStrok = 0;
					Fraction* tetta = new Fraction[num_l+num_v];
					FindVedElem(ocenki, matrixLIM, B, num_l, num_v, tetta, &nVedStolb, &nVedStrok);
					str += "\nНомер ведущей строки: " + IntegerToSystemString(nVedStrok) + "\nНомер ведущего столбца: " + IntegerToSystemString(nVedStolb) + "\nB ="; for(int i = 0; i < num_l + num_v; i++) { str += StdStringToSystemString(B[i].toString()) + "  "; } str += "\n";
					
//MessageBox::Show(str);
					Fraction VedElement = matrixLIM[nVedStrok][nVedStolb];
  					ConversionMatrix(matrixLIM, B, num_l, num_v, nVedStrok, nVedStolb, VedElement);
					MassBass[num_v + nVedStrok] = StoimostVCel[nVedStolb];
					MassBassIndex[num_v + nVedStrok] = nVedStolb;
				}
			}//цикл вайл флаг != тру
		 }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
private: bool CheckBoxNull(Fraction *NumBox, int NumberVariables)
		 {
			 bool flag = true;
			 for(int i = 0; i < NumberVariables; i++)
			 {
				 if (NumBox[i] != Fraction::Fraction(0))
				 {
					// MessageBox::Show(StdStringToSystemString(NumBox[0].toString()) + " != 0" );
					flag = false;
				 }
			 }//*/
			 return flag;
		 }
/*----------------------------- Функции для симплекса ------------------------------------*/
	private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 exit(0);
			 }

private: const wchar_t* StringToWchar_t(System::String^ str) //Начало блока конвертации(System::String^ -> const wchar_t;  std::string -> System::String^;  int -> System::String^; double -> System::String^)
		 {
			 pin_ptr<const wchar_t> wch = PtrToStringChars(str);
			 return wch;
		 }

private: System::Void сохранитьКакToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 SaveDialog->Filter = "|*.xlsx";
			 if(SaveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 System::String^ type;
				 if(id == 0) 
					 type = L"20FT";
				 else if(id == 1) 
					 type = L"40FT";
				 else if(id == 2) 

 type = L"40FTHQ";

				 Book *Nbook = xlCreateXMLBook();
				 Sheet *Ssheet;
				 Fraction num;
				 for(int i = 1; i < CcountKon+1; i++)
				 {
					 Fraction TotalCost = Fraction::Fraction(0);

					Ssheet = Nbook->addSheet(IntToWchar_t(i));
					Ssheet->writeStr(1,0, L"Наименование товара");
					Ssheet->writeStr(1,1, L"Колличество коробок, шт");
					Ssheet->writeStr(1,2, L"Себестоимость перевозки");
					for(int j = offset+1; j < offset+NumberVariables+1; j++)
					{
						Ssheet->writeStr(j-offset+1, 0, WchToConstWch(names[j-offset-1])/*(const wchar_t*)List->readStr(2,0)*/);
						num = Fraction::Fraction(List->readNum(j,i));
						if(num != 0)
							Ssheet->writeNum(j-offset+1, 1, num.getNumerator()/num.getDenominator());
						TotalCost += num*cost[j-offset-1];
						//Ssheet->writeNum(j-offset+1, 2, ((Fraction::Fraction(List->readNum(j,i))*Fraction::Fraction(stoimost)/TotalCost).getNumerator()/(Fraction::Fraction(List->readNum(j,i))*Fraction::Fraction(stoimost)/TotalCost).getDenominator()));
					}
					for(int j = offset+1; j < offset+NumberVariables+1; j++)
					{
						num = (Fraction::Fraction(Ssheet->readNum(j-offset+1,1))*Fraction::Fraction(stoimost)/TotalCost);
							if(num != 0)
								Ssheet->writeNum(j-offset+1, 2,num.getNumerator()/num.getDenominator());
					}
						//			 MessageBox::Show(StdStringToSystemString(TotalCost.toString()));
				 }

				 //MessageBox::Show(wchar_tToSysString(ConstWchToWchPtr(List->readStr(7,0))));
	/*
				 for(int i = 3; i < List->lastRow(); i++)
				 {
					 MessageBox::Show(ConstWchar_tToSysString(List->readStr(i,0)));
	//				 if(ConstWchar_tToSysString(List->readStr(i,0)) == type)
	//					 MessageBox::Show( "yeeee");
	//				 else MessageBox::Show("nooo");
				 }*/

				 if(Pbook->save(StringToWchar_t(SaveDialog->FileName)))
					 MessageBox::Show("Сохранено!");
else MessageBox::Show("Ошибка. Не удалось сохраненить файл!");
			 }
		 }
private: System::Void помощьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Если вы нашли недочеты или ошибки в программе, пожалуйста сообщите о них.\nКонтактный e-mail: ivanvladimirovich174@yandex.ru");
		 }
};
}
#include <iostream>
#include <cmath>
#include <sstream>
#include "string.h"
using namespace::std;

class Fraction
{
private:
	double m_Numerator;
	double m_Denominator;
	bool m_Corrupt;
public:
	Fraction( double number, double denominator, bool positive ); //первый конструктор
	Fraction( std::string &fractionString ){ parseFraction(fractionString);}			//второй конструктор
	Fraction() { m_Numerator = 1; m_Denominator = 0; m_Corrupt = true;} 												//третий конструктор
	Fraction(double num); 
	Fraction& FractPart();
	bool CheckFract();
	void parseFraction( std::string &fractionString );
	void reduceFraction();
	std::string toString();
	// Getters
	double getNumerator() { return m_Numerator; }
	double getDenominator() { return m_Denominator; }
	bool getCorrupt() { return m_Corrupt; }
	// Setters
	void setNumerator( double numerator ) { m_Numerator = numerator; }
	void setDenominator( double denominator ) { m_Denominator = denominator; }
	void setCorrupt( bool corrupt ) { m_Corrupt = corrupt; }
	// Own operators
	Fraction& operator + ( const Fraction &mulFraction );
	Fraction& operator - ( const Fraction &mulFraction );
	Fraction& operator * ( const Fraction &mulFraction );
	Fraction& operator / ( const Fraction &mulFraction );
	Fraction& operator -= ( const Fraction &mulFraction );
	Fraction& operator += ( const Fraction &mulFraction );
	bool operator > ( const Fraction &mulFraction );
	bool operator < ( const Fraction &mulFraction );
	bool operator >= ( const Fraction &mulFraction );
	bool operator <= ( const Fraction &mulFraction );
	bool operator != ( const Fraction &mulFraction );
	bool operator == ( const Fraction &mulFraction );
	//void operator - ();
};
#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// General Information about an assembly is controlled through the following
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
//
[assembly:AssemblyTitleAttribute("SimplexForm")];
[assembly:AssemblyDescriptionAttribute("")];
[assembly:AssemblyConfigurationAttribute("")];
[assembly:AssemblyCompanyAttribute("")];
[assembly:AssemblyProductAttribute("SimplexForm")];
[assembly:AssemblyCopyrightAttribute("Copyright (c)  2013")];
[assembly:AssemblyTrademarkAttribute("")];
[assembly:AssemblyCultureAttribute("")];

//
// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version
//      Build Number
//      Revision
//
// You can specify all the value or you can default the Revision and Build Numbers
// by using the '*' as shown below:

[assembly:AssemblyVersionAttribute("1.0.*")];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];

[assembly:SecurityPermission(SecurityAction::RequestMinimum, UnmanagedCode = true)];
#include "stdafx.h"
#include "fraction.h"


double integer(double Number)
{
	return Number < 0 ? ceil(Number) : floor(Number);
}

double balance(double c, double b)
{
	double a;
	if(c < 0) a = -c;
	else a = c;
	if(b != 0)
	{
		
while(a >= b)
		{
			a -= b;
		}
	}
	if ( c < 0)
		return -a;
	else return a;
}

double findNOD( double a, double b )
{
	while( b > 0)
	{
		double c = balance(a , b);
		a = b; b = c;
	}
	return a;
}

double findNOK( double a, double b )
{
	return findNOD( a, b ) * a * b;
}


Fraction::Fraction( double numerator = 1, double denominator = 1, bool positive = true ) :
m_Numerator(numerator), m_Denominator(denominator), m_Corrupt(false)
{

	if( m_Denominator == 0 ) m_Corrupt = true;
	else 
	{
		if( denominator < 0 && numerator < 0 || denominator < 0 && numerator > 0) { m_Numerator *= -1; m_Denominator *= -1; }
		if( !positive && numerator > 0 ) { m_Numerator *= -1; positive = false; }
		if( !positive && numerator <= 0 ) { m_Numerator *= -1; positive = true; }
	}
}

Fraction::Fraction(double number)
{
 	double test = 0;
	test = number;
	test++;
	float part = 0;
	double k = 1;
	while(modf(number, &part) != 0)
	{
		number*=10;
		k*=10;
	}
	modf(number, &number);
	m_Numerator = (double)number;
	m_Denominator = k;
	
m_Corrupt = false;
}

bool Fraction::CheckFract()
{
	if( !this->m_Corrupt )
	{
		if(this->m_Numerator == 0)
			return true;
		else return false;
	}
	else return false;
}

void Fraction::parseFraction( std::string &fractionString )
{
	if( fractionString != "" )
	{
		bool positive; // Знак выражения
		unsigned int offset = 0; // На сколько символов сдвигать поиск служебных
		switch (fractionString[0])
		{
			// Проверяем знак, если он вообще существует, сдвигаем поиск на один символ вправо
		case '+': positive = true; offset = 1; break;
		case '-': positive = false; offset = 1; break;
		default: positive = true; offset = 0; break;
		}
		unsigned int slashPos = fractionString.find( "/" ); // Ищем вхождение "/" в строку
		unsigned int spacePos = fractionString.find(" "); // Ищем вхождение пробела, который разделяет целую часть и дробную.
		// Если пробел существует, значит в выражении есть целая часть дроби
		if( spacePos != std::string::npos )
		{
			double fullPart = atoi( fractionString.substr(offset, spacePos-offset).c_str() ); // Шаманим
			double tempNumerator = atoi( fractionString.substr(spacePos+1, slashPos-offset).c_str() ); // С бубном
			// Stay the same
			m_Denominator = atoi( fractionString.substr(slashPos+1, fractionString.size()).c_str() ); // Лучше даже не пытаться понять эти строки
			// 2 3/9 -> 21/9
			m_Numerator = fullPart * m_Denominator + tempNumerator; // Переводим всё выражение в неправильную дробь
		}
		else
		{
			m_Numerator = atoi( fractionString.substr(offset, slashPos-offset).c_str() ); // Если же целой части не существует
			m_Denominator = atoi( fractionString.substr(slashPos+1, fractionString.size()).c_str() ); // Просто парсим
		}
		if( !positive ) m_Numerator *= -1; // Ставим нужный знак числителю
		this->reduceFraction(); // Сокращаем дробь (реализуем далее)
	}
}

void Fraction::reduceFraction()
{
	if( !m_Corrupt )
	{
		if((m_Numerator < 0 && m_Denominator < 0) || (m_Denominator < 0))
		{
			m_Numerator *= (-1); m_Denominator *= (-1);
		}
		double nod = findNOD( fabs((double)m_Numerator), (double)m_Denominator );
		this->setNumerator( m_Numerator / nod );
		this->setDenominator( m_Denominator / nod );
	}
}

std::string Fraction::toString()
{
	std::string formattedFraction;
	std::ostringstream ost;
	if(m_Denominator != 0)
	{
		if( m_Numerator < 0 ) formattedFraction.append( "-" );
		if(integer((fabs((double)m_Numerator) / (double)m_Denominator)) != 0)
			ost << integer((fabs((double)m_Numerator) / (double)m_Denominator));
		formattedFraction.append(ost.str());
		if(ost.str() != "" && balance(fabs((double)m_Numerator), (double)m_Denominator) != 0)
		{
			formattedFraction.append( " " );
		}
		ost.str("");
		if(balance(fabs((double)m_Numerator), (double)m_Denominator) != 0)
		{
			ost << balance(fabs((double)m_Numerator), (double)m_Denominator);
			formattedFraction.append( ost.str());
			formattedFraction.append( "/" );
			ost.str("");
			ost << m_Denominator;
			formattedFraction.append( ost.str()); 
			ost.str("");
		}
		if(balance(fabs((double)m_Numerator), (double)m_Denominator) == 0 && integer((fabs((double)m_Numerator) / (double)m_Denominator) == 0))
		{
			formattedFraction.append("0");
		}
	}
	else { formattedFraction.append( "-" ); }
	ost.str("");
	return formattedFraction;;
}

Fraction& Fraction::FractPart(void)
{
	Fraction *a = new Fraction(0,1,true);
	
if(this->getNumerator() == this->getDenominator() || this->getNumerator() == this->getDenominator()*(-1))
		return *a;
	else {
		if( !this->m_Corrupt )
		{
			if(m_Numerator < 0)
			{//cout << "[" << m_Denominator << " - " << balance(m_Numerator,m_Denominator) << "] ";
				a->setNumerator(m_Denominator + balance(m_Numerator,m_Denominator));
			}
			else a->setNumerator(balance(m_Numerator,m_Denominator));
			a->setDenominator(m_Denominator);
		}
		else a->setCorrupt(true);
	}
	return *a;
}
Fraction& Fraction::operator * ( const Fraction &mulFraction )
{
	Fraction *a = new Fraction(0,1,true);
	if( !this->m_Corrupt && !mulFraction.m_Corrupt )
	{
		a->setNumerator( m_Numerator * mulFraction.m_Numerator );
		a->setDenominator( m_Denominator * mulFraction.m_Denominator );
		a->reduceFraction();
	}
	else a->setCorrupt(true);
	return *a;
}

Fraction& Fraction::operator / ( const Fraction &mulFraction )
{
	Fraction *a = new Fraction(0,1,true);
	if( !this->m_Corrupt && !mulFraction.m_Corrupt && mulFraction.m_Numerator != 0)
	{
		a->setNumerator( m_Numerator * mulFraction.m_Denominator );
		a->setDenominator( m_Denominator * mulFraction.m_Numerator );
		a->reduceFraction();
	}
	else
		a->setCorrupt(true);
	return *a;
}

Fraction& Fraction::operator - ( const Fraction &mulFraction )
{
	Fraction *a = new Fraction(1,1,true);
	if( !this->m_Corrupt && !mulFraction.m_Corrupt )
	{
		a->setNumerator( m_Numerator * mulFraction.m_Denominator - m_Denominator * mulFraction.m_Numerator );
		a->setDenominator( m_Denominator*mulFraction.m_Denominator );
		a->reduceFraction();
	}
	else
	
	a->setCorrupt(true);
	return *a;
}

Fraction& Fraction::operator + ( const Fraction &mulFraction )
{
	Fraction *a = new Fraction(1,1,true);
	if( !this->m_Corrupt && !mulFraction.m_Corrupt )
	{
		a->setNumerator( m_Numerator * mulFraction.m_Denominator + m_Denominator * mulFraction.m_Numerator );
		a->setDenominator( m_Denominator*mulFraction.m_Denominator );
		a->reduceFraction();
	}
	else
		a->setCorrupt(true);
	return *a;
}

Fraction& Fraction::operator -= ( const Fraction &mulFraction )
{
	double relNumerator;
	double mulNumerator;
	if( !this->m_Corrupt && !mulFraction.m_Corrupt )
	{
		double unionDenominator = findNOK( m_Denominator, mulFraction.m_Denominator );
		relNumerator = m_Numerator * mulFraction.m_Denominator;
		mulNumerator = m_Denominator * mulFraction.m_Numerator;
		this->setNumerator( relNumerator - mulNumerator );
		this->setDenominator( unionDenominator );
		this->reduceFraction();
	}
	else
	{
		this->setCorrupt(true);
	}
	return *this;
}
Fraction& Fraction::operator += ( const Fraction &mulFraction )
{
	if( !this->m_Corrupt && !mulFraction.m_Corrupt )
	{
		this->setNumerator( m_Numerator * mulFraction.m_Denominator + m_Denominator * mulFraction.m_Numerator );
		this->setDenominator( m_Denominator * mulFraction.m_Denominator );
		this->reduceFraction();
	}
	else
	{
		this->setCorrupt(true);
	}
	return *this;
}

bool Fraction::operator < ( const Fraction &mulFraction )
{

	if(m_Numerator*mulFraction.m_Denominator < mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;

}
bool Fraction::operator > ( const Fraction &mulFraction )
{
	if(m_Numerator*mulFraction.m_Denominator > mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;

}
bool Fraction::operator <= ( const Fraction &mulFraction )
{
	if(m_Numerator*mulFraction.m_Denominator <= mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;
}
bool Fraction::operator >= ( const Fraction &mulFraction )
{
	if(m_Numerator*mulFraction.m_Denominator >= mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;
}
bool Fraction::operator != ( const Fraction &mulFraction )
{
	if(m_Numerator*mulFraction.m_Denominator != mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;
}
bool Fraction::operator == ( const Fraction &mulFraction )
{
	if(m_Numerator*mulFraction.m_Denominator == mulFraction.m_Numerator * m_Denominator)
		return true;
	else return false;
// SimplexForm.cpp : main project file.

#include "stdafx.h"
#include <tchar.h>
#include <sstream>
#include <iostream>
#include <cmath>
#include "libxl.h"
#include "fraction.h"
using namespace::std;
using namespace libxl;
#include "Form1.h"

using namespace SimplexForm;

[STAThreadAttribute]
int main(array<System::String ^> ^args)

{
	setlocale(LC_ALL, "Russian");
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}

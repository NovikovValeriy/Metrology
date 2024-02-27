#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->operatorTable->resizeColumnsToContents();
    ui->operandTable->resizeColumnsToContents();
    ui->textBrowser->setReadOnly(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<std::map<std::string, int>> MainWindow::parse()
{
    std::string fileContent = line.toStdString();

    std::map<std::string, int> operandDict;
    std::map<std::string, int> operandDict_;
    std::map<std::string, int> operatorDict;
    std::vector<std::map<std::string, int>> dicts;

    std::regex operandRegex("(\\$([_a-zA-Z_][a-zA-Z0-9_]*))|(\\d+)|(true)|(false)|(\"([^\"]*)\")|(\'([^\']*)\')");
    std::regex operatorRegex("\\[|\\{|\\;|\\+\\+|--(?!\\=)|\\*\\*|==|!=|<=|>=|&&|\\|\\||\\+=(?!\\=)|-=\\b(?!\\=)|\\*=(?!\\=)|/=(?!\\=)|%(?!\\=)|<<=|>>=|&=|\\|=|\\^=|~|!(?!\\=)|\\+(?!\\+)|-(?!\\-)|\\*(?!\\=)|/(?!\\=)|%(?!\\=)|<<|>>|&(?!\\=)|\\|(?!\\=)|\\^=|=|<|>|\\?|:|===|!==|<>|->|::\\b|and\\b|or\\b|xor\\b|clone\\b|new\\b|instanceof\\b|print\\b|var\\b|if\\b|else\\b|elseif\\b|switch\\b|case\\b|default\\b|break\\b|continue\\b|while\\b|do\\b|for\\b|foreach\\b|declare\\b|return\\b|try\\b|throw\\b|catch\\b|finally\\b|function\\b|const\\b|abstract\\b|interface\\b|extends\\b|implements\\b|public\\b|protected\\b|private\\b|static\\b|final\\b|namespace\\b|use\\b|require\\b|require_once\\b|include\\b|include_once\\b|global\\b|goto\\b"); ("\\+\\+|--(?!\\=)|\\*\\*|==|!=|<=|>=|&&|\\|\\||\\+=(?!\\=)|-=\\b(?!\\=)|\\*=(?!\\=)|/=(?!\\=)|%(?!\\=)|<<=|>>=|&=|\\|=|\\^=|~|!(?!\\=)|\\+(?!\\+)|-(?!\\-)|\\*(?!\\=)|/(?!\\=)|%(?!\\=)|<<|>>|&(?!\\=)|\\|(?!\\=)|\\^=|=|<|>|\\?|:|===|!==|<>|->|::\\b|and\\b|or\\b|xor\\b|clone\\b|new\\b|instanceof\\b|print\\b|var\\b|if\\b|else\\b|elseif\\b|switch\\b|case\\b|default\\b|break\\b|continue\\b|while\\b|do\\b|for\\b|foreach\\b|declare\\b|return\\b|try\\b|throw\\b|catch\\b|finally\\b|function\\b|const\\b|abstract\\b|interface\\b|extends\\b|implements\\b|public\\b|protected\\b|private\\b|static\\b|final\\b|namespace\\b|use\\b|require\\b|require_once\\b|include\\b|include_once\\b|global\\b|goto\\b");

    std::sregex_iterator operandIter(fileContent.begin(), fileContent.end(), operandRegex);
    std::sregex_iterator operandEnd;

    for (; operandIter != operandEnd; ++operandIter) {
        std::string operand = operandIter->str();
        operandDict_[operand]++;
    }

    for (const auto& pair : operandDict_){
        operandDict[pair.first/*.substr(1)*/] = pair.second;
    }

    std::sregex_iterator operatorIter(fileContent.begin(), fileContent.end(), operatorRegex);
    std::sregex_iterator operatorEnd;

    for (; operatorIter != operatorEnd; ++operatorIter) {
        std::string op = operatorIter->str();
        operatorDict[op]++;
    }

    dicts.push_back(operandDict);
    dicts.push_back(operatorDict);
    return dicts;
}

void MainWindow::on_openFileButton_clicked()
{
    QString backup = fileAdress;
    fileAdress = QFileDialog::getOpenFileName(this, "Открыть файл", "C:/Users/dzmitry/source/repos/4sem/Metrology/Lab1/Metrology/MSACIT_LWD_1", "PHP files (*.php);; Text files (*.txt)");
    QFile file(fileAdress);
    file.open(QIODevice::ReadWrite);
    line.clear();
    while(!file.atEnd()){
        line += file.readLine();
    }
    ui->textBrowser->setText(line);
    file.close();
}

void MainWindow::on_calculateButton_clicked()
{
    int nu1 = 0, nu2 = 0, N1 = 0, N2 = 0;
    QTableWidgetItem *item;
    const auto dicts = parse();
    ui->operandTable->setRowCount(dicts[0].size() + 1);
    ui->operatorTable->setRowCount(dicts[1].size() + 1);
    int i = 0;
    for (const auto& entry : dicts[0]){
        item = new QTableWidgetItem("");
        ui->operandTable->setVerticalHeaderItem(i, item);
        item = new QTableWidgetItem(QString::number(i + 1));
        ui->operandTable->setItem(i, 0, item);
        item = new QTableWidgetItem(QString::fromStdString(entry.first));
        ui->operandTable->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::number(entry.second));
        ui->operandTable->setItem(i, 2, item);
        i++;
        N2 += entry.second;
    }
    nu2 = i;
    item = new QTableWidgetItem("");
    ui->operandTable->setVerticalHeaderItem(i, item);
    item = new QTableWidgetItem("η₂ = " + QString::number(nu2));
    ui->operandTable->setItem(i, 0, item);
    item = new QTableWidgetItem("N₂ = " + QString::number(N2));
    ui->operandTable->setItem(i, 2, item);

    i = 0;
    for (const auto& entry : dicts[1])
    {
        item = new QTableWidgetItem("");
        ui->operatorTable->setVerticalHeaderItem(i, item);
        item = new QTableWidgetItem(QString::number(i + 1));
        ui->operatorTable->setItem(i, 0, item);
        if (entry.first == "["){
            item = new QTableWidgetItem("[ ]");
        }
        else if (entry.first == "{"){
            item = new QTableWidgetItem("{ }");
        }
        else item = new QTableWidgetItem(QString::fromStdString(entry.first));
        ui->operatorTable->setItem(i, 1, item);
        item = new QTableWidgetItem(QString::number(entry.second));
        ui->operatorTable->setItem(i, 2, item);
        i++;
        N1 += entry.second;
    }
    nu1 = i;
    item = new QTableWidgetItem("");
    ui->operatorTable->setVerticalHeaderItem(i, item);
    item = new QTableWidgetItem("η₁ = " + QString::number(nu1));
    ui->operatorTable->setItem(i, 0, item);
    item = new QTableWidgetItem("N₁ = " + QString::number(N1));
    ui->operatorTable->setItem(i, 2, item);

    ui->operatorTable->resizeColumnsToContents();
    ui->operandTable->resizeColumnsToContents();

    QString dictionary = "Словарь программы: η = " + QString::number(nu1) + " + " + QString::number(nu2) + " = " + QString::number(nu1 + nu2);
    QString length = "Длина программы: N = " + QString::number(N1) + " + " + QString::number(N2) + " = " + QString::number(N1 + N2);
    QString volume = "Объем программы: V = " + QString::number(N1 + N2) + "*log" + QString::number(nu1 + nu2) + " = " + QString::number((N1 + N2) * log2(nu1 + nu2));
    QMessageBox::information(this, "Метрика Холстеда", dictionary + "\n" + length + "\n" + volume);
}

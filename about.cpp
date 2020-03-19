#include "about.h"

#include <QCoreApplication>
#include <QString>

#include "revision_utils.hpp"

#include "ui_about.h"
#include "moc_about.cpp"

CAboutDlg::CAboutDlg(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CAboutDlg)
{
  ui->setupUi(this);

  ui->labelTxt->setText ("<html><h2>"
                         + QCoreApplication::applicationName () + " v"
	 					 + QCoreApplication::applicationVersion () + "  HF software" + "</h2>\n\n"
                         "It is modified WSJT-X software forked from WSJT-X v1.7 r6462, <br>"
                         "FT8 code is forked from WSJT-X v1.8 and v2.0, <br>"
                         "FT4 code is forked from WSJT-X v2.1, <br>"
                         "WSPR code is forked from WSJT-X v2.1.2, <br>"
                         "&copy; 2001-2020 by Joe Taylor, K1JT.<br><br>"
                         "JTDX supports FT8, FT4, JT9, T10 and JT65A digital modes for HF <br>"
                         "amateur radio communication, focused on DXing <br>"
                         "and being shaped by community of DXers. <br>"
                         "&copy; 2016-2020 by Igor Chernikov UA3DJY and Arvo Järve ES1JA. <br>"
                         "It is created with contributions from 9A5CW, CE2EC, CT1AXS, DK7UY, <br>"
                         "DO1IP, EA7QL, ES2HV, ES5TF, ES4RLH, G7OED, IZ5ILJ, JA2BQX, JP1LRT, <br>" 
                         "LU9DO, MM0HVU, N6ML, NL9222, OE1MWW, R3BB, RK3AOL, RA4UDC, RW4O, R0JF, <br>" 
                         "SP2L, SV1IYF, UA3ALE, US-E-12, VE3NEA, VK3AMA, VK6KXW, VK7YUM, VR2UPU <br>"
                         "and LY3BG family: Vytas and Rimas Kudelis. <br><br>"
                         "<br><br>"
                         "JTDX is licensed under the terms of Version3<br>"
                         "of the GNU General Public License(GPL)<br>"
                         "<a href=\"https://www.gnu.org/licenses/gpl-3.0.txt\">"
                         "https://www.gnu.org/licenses/gpl-3.0.txt</a>");
}

CAboutDlg::~CAboutDlg()
{
}

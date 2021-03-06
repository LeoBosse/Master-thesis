#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <math.h>  

void plot_CR_protons(){
	
	TCanvas *CB = new TCanvas("bin_ex","bin_ex", 900,900);
	CB->SetBorderMode(0);
	CB->SetBorderSize(2);
// 	double rm = CB->GetRightMargin();
	double lm = CB->GetLeftMargin();
	CB->SetLeftMargin(lm+0.02);
	CB->SetRightMargin(lm-0.02);
	CB->SetFillStyle(1001);
	CB->SetFillColor(10);
	CB->SetLogx();
	CB->SetLogy();
	CB->cd();
	
	
	
	double data_X[74] = {0.01, 1.077389706640028,
1.422632172244503,
1.2511112962418927,
1.6176042798141996,
1.8174465037004295,
2.045989961303636,
2.52870430399155,
2.803787118106809,
2.2660924995716756,
3.112873672917838,
3.456065572607945,
3.8370586209530972,
4.196829994651156,
4.659484136899371,
5.096320865185047,
5.658081603868238,
6.188567627843854,
6.768790548763674,
7.403413560012316,
8.097462164919019,
8.846628223648075,
9.664148645812244,
10.54480422160275,
11.4456323740115,
12.410609011167864,
13.562441956543445,
14.515690769900079,
15.925887735868908,
17.120602990661045,
18.711010336232,
20.20833819270285,
21.696514022631742,
23.71191069875105,
25.45818883953053,
27.49535133239872,
29.519938463861127,
32.454312305102505,
35.05130410905703,
37.6326788008352,
40.644043130106766,
43.89669861356426,
46.85082216185883,
50.900796905242345,
53.68610965040769,
57.6396445736058,
61.88432442219936,
66.83654887032614,
71.75850413632597,
77.50118311185454,
83.20819470780117,
90.40137948352027,
95.34783081207408,
102.97831294038758,
112.54524228222424,
119.40895634006161,
131.27809709469062,
140.94460190881884,
153.1273006855424,
167.35012094323548,
183.9805208355015,
201.06906002508586,
223.68695574373405,
245.91492048602487,
273.5754393762064,
307.9684211299272,
350.81784785384633,
409.215043605503,
483.01425717423405,
587.2599150255447,
731.1175671711399,
971.4700989715755,
1433.5143586328973};
	
	double data_Y[74] = {1e-10, 624.0487911410949,
648.4570079997848,
660.9800632247043,
613.3163615945427,
557.9600120007105,
498.3592331799641,
395.9708835945538,
341.2208014310774,
443.3910003055236,
287.16139637847516,
248.71473829029304,
209.31101283335394,
173.63616430637433,
146.12709188566942,
117.78607193191523,
96.31625535675326,
78.75991527512393,
64.4037107876388,
52.66432738949253,
41.844394288165475,
34.14264088946092,
27.539055000676104,
21.648621647321452,
17.884435944316333,
13.902131152121838,
11.412729382473787,
9.28040391550989,
7.360793867666892,
5.987254550942007,
4.766700022204424,
3.882477172236957,
3.1622776601683698,
2.4890842912355695,
2.0506011099773476,
1.6512840354510336,
1.3146552533350764,
1.0830623660351253,
0.8721557721439946,
0.7185146765535422,
0.5785970800743568,
0.4766700022204424,
0.38824771722369605,
0.31622776601683666,
0.25756751569612535,
0.20978874175881712,
0.17087293034526763,
0.13917600191503868,
0.11335885368101141,
0.09338928054889335,
0.07520342562106032,
0.061955406088756895,
0.049890723498818484,
0.04110185153009264,
0.03347745810705725,
0.026958335217264668,
0.02195756405794087,
0.017481321395642728,
0.013917600191503867,
0.010707867049863911,
0.008145000008709257,
0.006266567225263485,
0.004821346193585786,
0.0036258174986271317,
0.002726738965735467,
0.0018933361312185408,
0.0012997546688516893,
0.0008821542980788808,
0.0005591453949755616,
0.00033477458107057244,
0.0001871876653604853,
0.00008524974121288637,
0.000030214752293273638};
	
	CB->cd();


	double min = 0.01, max = 2e3;
	
	TGraph* g_data = new TGraph(74,data_X,data_Y);
	g_data->Draw("AP");
	g_data->SetMarkerStyle(20);
	g_data->SetMarkerSize(1);
	g_data->SetMarkerColor(kBlue);
	g_data->GetXaxis()->SetTitle("R (GV)");
	g_data->GetYaxis()->SetTitle("#phi (GV^{-1} cm^{-2} s^{-1} sr^{-1})");
	//g_data->GetXaxis()->SetRangeUser(min, max);
	g_data->GetYaxis()->SetRangeUser(1e-6, 5e3);
	g_data->GetXaxis()->SetTitleOffset(1.3);
	g_data->GetYaxis()->SetTitleOffset(1.5);
	g_data->GetXaxis()->CenterTitle();
	g_data->GetYaxis()->CenterTitle();
	
	int norm_point = 60;
	
	
	int const N = 100000;
	double x[N], y[N];
	

	for (Int_t i=0; i<N; i++) {
		x[i] = min + i * 0.05;
		double b = 14;
		if(x[i] < b)
			y[i] = pow(x[i], -0.7) * pow(b, -2.85) / pow(b, -0.7) * data_Y[norm_point] / pow(data_X[norm_point], -2.85);
		else
			y[i] = pow(x[i], -2.85) * data_Y[norm_point] / pow(data_X[norm_point], -2.85);
	}
	TGraph* g_MC = new TGraph(N,x,y);
	g_MC->Draw("sameL");
	//g_MC->SetLineStyle(2);
	g_MC->SetLineWidth(4);
	g_MC->SetLineColor(kYellow+3);
	g_MC->SetMarkerStyle(23);
	g_MC->SetMarkerSize(1);
	g_MC->SetMarkerColor(kYellow+3);
	for (Int_t i=0; i<N; i++) {
		x[i] = min + i * 0.05;
		double b = 6;
		if(x[i] < b)
			y[i] = pow(x[i], -0.7) * pow(b, -2.85) / pow(b, -0.7) * data_Y[norm_point] / pow(data_X[norm_point], -2.85);
		else
			y[i] = pow(x[i], -2.85) * data_Y[norm_point] / pow(data_X[norm_point], -2.85);
	}
	TGraph* g_MC = new TGraph(N,x,y);
	g_MC->Draw("sameL");
	//g_MC->SetLineStyle(2);
	g_MC->SetLineWidth(4);
	g_MC->SetLineColor(kYellow+3);
	g_MC->SetMarkerStyle(23);
	g_MC->SetMarkerSize(1);
	g_MC->SetMarkerColor(kYellow+3);

	for (Int_t i=0; i<N; i++) {
		x[i] = min + i * 0.1;
		y[i] = pow(x[i], -2.85) * data_Y[norm_point] / pow(data_X[norm_point], -2.85);
	}
	TGraph* g_prop = new TGraph(N,x,y);
	g_prop->Draw("sameL");
	g_prop->SetLineColor(kRed+1);
	//g_prop->SetLineStyle(2);
	g_prop->SetLineWidth(4);
	g_prop->SetMarkerStyle(20);
	g_prop->SetMarkerSize(1);
	g_prop->SetMarkerColor(kRed+1);


	for (Int_t i=0; i<N; i++) {
		x[i] = min + i * 0.05;
		y[i] = pow(x[i], -2.1) * data_Y[norm_point] / pow(data_X[norm_point], -2.1);
	}
	TGraph* g_SCR = new TGraph(N,x,y);
	g_SCR->Draw("sameL");
	g_SCR->SetLineColor(kMagenta+1);
	//g_SCR->SetLineStyle(2);
	g_SCR->SetLineWidth(4);
	g_SCR->SetMarkerColor(kMagenta+1);
	g_SCR->SetMarkerStyle(22);
	g_SCR->SetMarkerSize(1);


	TLegend *l_dat = new TLegend(0.2,0.1,0.6,0.5,""); //(0.57,0.7,0.7,0.89)
	l_dat->SetBorderSize(0);
	l_dat->SetFillStyle(0);
	l_dat->SetTextSize(0.025);
	l_dat->SetTextFont(62);

	l_dat->AddEntry(g_data, "AMS-02 proton data", "p");
	l_dat->AddEntry(g_prop,"Interstellar ~R^{-2.85}","l");
	l_dat->AddEntry(g_MC, "Molecular clouds ~R^{-0.7} (below break)", "l");
	l_dat->AddEntry(g_SCR,"Point source ~R^{-2.1}","l");

	l_dat->Draw();

	char profile_name[300];
        sprintf(profile_name,"./CR_protons.png");
        CB->SaveAs(profile_name);
        sprintf(profile_name,"./CR_protons.pdf");
	CB->SaveAs(profile_name);
        sprintf(profile_name,"./CR_protons.C");
	CB->SaveAs(profile_name);
        sprintf(profile_name,"./CR_protons.root");
	CB->SaveAs(profile_name);



}

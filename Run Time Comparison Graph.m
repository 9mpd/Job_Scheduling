Copyright (c) 2021, 9mpd
All rights reserved.

This source code is licensed under the MIT license found in the
LICENSE file in the root directory of this source tree.

% Plotting the Experimental Results of Greedy Algorithm &
% Brute Force Algorithm in Job Scheduling.

clear 
close all
clc

% Table for Greedy Algorithm.
% Number of Jobs & Time Required to schedule them.
T1 = table('Size', [8 2], 'VariableTypes', repmat("double", 1,2));
T1.Properties.VariableNames([1 2]) = {'No. of Jobs' 'Time Taken (ms)'};
T1{1,1} = 5; T1{1,2} = 2.7*10^(-3);
T1{2,1} = 10; T1{2,2} = 3.0*10^(-3);
T1{3,1} = 20; T1{3,2} = 5.1*10^(-3);
T1{4,1} = 30; T1{4,2} = 6.3*10^(-3);
T1{5,1} = 50; T1{5,2} = 8.3*10^(-3);
T1{6,1} = 80; T1{6,2} = 2.03*10^(-2);
T1{7,1} = 100; T1{7,2} = 4.15*10^(-2);
T1{8,1} = 200; T1{8,2} = 1.87*10^(-1);

% Table for Brute Force Algorithm.
% Number of Jobs & Time Required to schedule them.
T2 = table('Size', [8 2], 'VariableTypes', repmat("double", 1,2));
T2.Properties.VariableNames([1 2]) = {'No. of Jobs' 'Time Taken (ms)'};
T2{1,1} = 3; T2{1,2} = 1.59*10^(-2);
T2{2,1} = 5; T2{2,2} = 3.90*10^(-2);
T2{3,1} = 7; T2{3,2} = 2.80*10^(-1);
T2{4,1} = 10; T2{4,2} = 1.81*10^(0);
T2{5,1} = 15; T2{5,2} = 8.69*10^(1);
T2{6,1} = 18; T2{6,2} = 7.12*10^(2);
T2{7,1} = 20; T2{7,2} = 3.71*10^(3);
T2{8,1} = 21; T2{8,2} = 7.14*10^(3);

% Plotting the Graph of Tables, T1 & T2.
figure;
P1 = plot(T1{1:7,1},T1{1:7,2},"r*-");
hold on;
P2 = plot(T2{1:3,1},T2{1:3,2},"bo-");
xticks(0:10:100);
yticks(0:0.02:0.3);
title("\color{magenta}Job Scheduling");
xlabel("Number of Jobs");
xh = get(gca,'xlabel');
p = get(xh,'position');
p(2) = 1.2*p(2) ;       
set(xh,'position',p);
ylabel("Time in milliseconds");
yh = get(gca,'ylabel');
q = get(yh,'position');
q(2) = 1.2*q(2);       
set(yh,'position',q);
lgd=legend([P1 P2],{'Greedy','Brute Force'},'Position',[0.7 0.7 0.05 0.05]);
hold off;



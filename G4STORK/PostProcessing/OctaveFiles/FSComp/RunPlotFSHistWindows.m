close all;
%clear all;
clc;

numIso=2;
numFS=43;
Directory = 'C:\Users\Wesley\Downloads\';
FSDir = {'Elastic\FS\', 'Capture\FS\', 'Fission\FS\', 'Fission\FC\', 'Fission\SC\', 'Fission\TC\', 'Fission\LC\', 'Inelastic\F01\',...
        'Inelastic\F02\', 'Inelastic\F03\', 'Inelastic\F04\', 'Inelastic\F05\', 'Inelastic\F06\', 'Inelastic\F07\', 'Inelastic\F08\', 'Inelastic\F09\',...
        'Inelastic\F10\', 'Inelastic\F11\', 'Inelastic\F12\', 'Inelastic\F13\', 'Inelastic\F14\', 'Inelastic\F15\', 'Inelastic\F16\', 'Inelastic\F17\',...
        'Inelastic\F18\', 'Inelastic\F19\', 'Inelastic\F20\', 'Inelastic\F21\', 'Inelastic\F22\', 'Inelastic\F23\', 'Inelastic\F24\', 'Inelastic\F25\',...
        'Inelastic\F26\', 'Inelastic\F27\', 'Inelastic\F28\', 'Inelastic\F29\', 'Inelastic\F30\', 'Inelastic\F31\', 'Inelastic\F32\', 'Inelastic\F33\',...
        'Inelastic\F34\', 'Inelastic\F35\','Inelastic\F36\'};
%isoList = {'1_1_Hydrogen.txt', '1_2_Hydrogen.txt'};

for i=4:1:7
    fileDiff = strcat(Directory, FSDir(i), 'FileDiffList.txt');
    fileDiff=[fileDiff{:}];
    fid = fopen(fileDiff,'rt','n');
    if((fid>-1)&&(~feof(fid)))
        fgetl(fid);
        fgetl(fid);
        numIso=0;
        while((numIso<1)&&(feof(fid)~=1))
            line=fgetl(fid);
            strEnd=strfind(line,'has');
            if(size(strEnd)~=0)
                isoName=line(1:strEnd(1)-1);
                fileName = strcat(Directory, FSDir(i), isoName, '.txt');
                [fileName{:}]
                PlotFSHistWindows(fileName);
                numIso=numIso+1;
            end
        end
    end
    fclose(fid);
end

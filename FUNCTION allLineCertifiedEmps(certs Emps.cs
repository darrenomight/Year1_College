FUNCTION allLineCertifiedEmps(certs Emps[], team Team[], int size)
    FOR int i = 0; i < size; INCREMENT i 
        IF Emps[i].certs == {1,1,1} 
            FOR int j = 0; j < size; INCREMENT j 
                IF Team[j].id == Emps[i].id 
                    PRINT(team[j].firstName)
                    PRINT(team[j].surname)
                    PRINT(team[j].line)
                    PRINT(team[j].id)
                ENDIF 
            ENDFOR 
        ENDIF 
    ENDFOR
ENDFUNCTION 
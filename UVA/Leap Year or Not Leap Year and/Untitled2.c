if ((!m4 && m100) || !m400)
        {
            printf("This is leap year.\n");
            if (!m15)
                printf("This is huluculu festival year.\n");
            if (!m55)
                printf("This is bulukulu festival year.\n");
        }
        else
        {
            if (!m15)
                printf("This is huluculu festival year.\n");
            else
                printf("This is an ordinary year.\n");
        }
    }
    return 0;
}

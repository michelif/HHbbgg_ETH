import pandas as pd


# -------------------------------------------------------------------------------------------
def read_data(fname,columns):

    df = pd.read_hdf(fname,columns=columns)

    return df

    
    

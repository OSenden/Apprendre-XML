<?xml version="1.0" encoding="UTF-8"?>

<!--
    Document   : blibliotheque.xsl
    Created on : 5 septembre 2019, 15:13
    Author     : osenden
    Description:
        Purpose of transformation follows.
-->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:output method="html"/>

    <!-- TODO customize transformation rules 
         syntax recommendation http://www.w3.org/TR/xslt 
    -->
    
    <xsl:template match="biblio">
        <html> 
            <body> 
                <xsl:apply-templates />     
            </body>
        </html>
    </xsl:template>
    
    <xsl:template match="allee">
        <h1>Allee 
        <xsl:value-of select="numAllee" />
        </h1>
        <hr/>
        <xsl:apply-templates />
    </xsl:template>
            
    <xsl:template match="unRayon">
        <h3>Rayon
        <xsl:value-of select="numRayon" />
        </h3>
        <table border="1">
            
            <tr>
                <th>Catégorie de l'ouvrage</th>
                <th>Titre</th>
                <th>Auteur</th>
                <th>Numero</th>
            </tr>
            <xsl:apply-templates/>
            
        </table>
    </xsl:template>
    
    <xsl:template match="ouvrage">
        <tr>
            <td>
                <xsl:value-of select="@typeOuvrage" />
            </td> 
            <xsl:apply-templates/>
        
    
        
        </tr>
    </xsl:template>
    
    <xsl:template match="titre">
        <td>
            <xsl:value-of select="." />
        </td> 
    </xsl:template>
    
    <xsl:template match="auteur">
        <td>
            <xsl:value-of select="." />
        </td> 
    </xsl:template>
    
    <xsl:template match="numOuvrage">
        <td>
            <xsl:value-of select="." />
        </td> 
    </xsl:template>
    

    

</xsl:stylesheet>
